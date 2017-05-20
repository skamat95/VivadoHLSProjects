#include "ClusterFinder.hh"

uint16_t GetPeakBinOf5(uint16_t et[5], uint16_t etSum) {
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=et complete dim=0
  uint16_t iEtSum = 
    (et[0] >> 1)                +  // 0.5xet[0]
    (et[1] >> 1) + et[1]        +  // 1.5xet[1]
    (et[2] >> 1) + (et[2] << 1) +  // 2.5xet[2]
    (et[3] << 2) - (et[3] >> 1) +  // 3.5xet[3]
	(et[4] << 2) + (et[4] >> 1) ;  // 4.5xet[4]
  uint16_t iAve = 0xBEEF;
  if(     iEtSum <= etSum) iAve = 0;
  else if(iEtSum <= (etSum << 1)) iAve = 1;
  else if(iEtSum <= (etSum + (etSum << 1))) iAve = 2;
  else if(iEtSum <= (etSum << 2)) iAve = 3;
  else iAve = 4;
  return iAve;
}

bool ClusterFinder(uint16_t crystals[5][5],
		   uint16_t *peakEta,
		   uint16_t *peakPhi,
		   uint16_t *bigclusterET,
		   uint16_t *smallclusterET) {
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=crystals complete dim=0
  *bigclusterET = 0;
  *smallclusterET=0;
  uint16_t phiStripSum[5];
#pragma HLS ARRAY_PARTITION variable=phiStripSum complete dim=0
  for(int phi = 0; phi < 5; phi++) {
#pragma HLS_UNROLL
    phiStripSum[phi] = 0;
    for(int eta = 0; eta < 5; eta++) {
#pragma HLS_UNROLL
      phiStripSum[phi] += crystals[eta][phi];
    }
  }
  uint16_t etaStripSum[5];
#pragma HLS ARRAY_PARTITION variable=phiStripSum complete dim=0
  for(int eta = 0; eta < 5; eta++) {
#pragma HLS_UNROLL
    etaStripSum[eta] = 0;
    for(int phi = 0; phi < 5; phi++) {
#pragma HLS_UNROLL
      etaStripSum[eta] += crystals[eta][phi];
    }
  }
  for(int phi = 0; phi < 5; phi++) {
#pragma HLS_UNROLL
    *bigclusterET += phiStripSum[phi];
    
  }
  *peakEta = GetPeakBinOf5(etaStripSum, *bigclusterET);
  *peakPhi = GetPeakBinOf5(phiStripSum, *bigclusterET);

  for(int dE =- 1; dE <=1; dE++){
#pragma HLS_UNROLL
	  for(int dP =-1; dP<=1; dP++){
#pragma HLS_UNROLL
	    int eta = *peakEta + dE;
	    int phi = *peakPhi + dP;
	    if(phi>=0 && phi <5){
	      if(eta >=0 && eta <5){
		*smallclusterET+= crystals[eta][phi];
	      }
	    }
	  }
  }
  return true;
}
