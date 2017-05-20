#include "TowerFinder.hh"
#include "ClusterFinder.hh"

#include <iostream>
using namespace std;

bool TowerFinder(uint16_t crystals[4][17][5][5],
		 uint16_t peakEta[4][17],
		 uint16_t peakPhi[4][17],
		 uint16_t largeclusterET[4][17],
		 uint16_t smallclusterET[4][17]
		   ) {
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=crystals complete dim=0
#pragma HLS ARRAY_PARTITION variable=peakEta complete dim=0
#pragma HLS ARRAY_PARTITION variable=peakPhi complete dim=0
#pragma HLS ARRAY_PARTITION variable=largeclusterET complete dim=0
#pragma HLS ARRAY_PARTITION variable=smallclusterET complete dim=0

  uint16_t preMergePeakEta[4][17];
  uint16_t preMergePeakPhi[4][17];
  uint16_t preMergelargeclusterET[4][17];
  uint16_t preMergesmallclusterET[4][17];
#pragma HLS ARRAY_PARTITION variable=preMergePeakEta complete dim=0
#pragma HLS ARRAY_PARTITION variable=preMergePeakPhi complete dim=0
#pragma HLS ARRAY_PARTITION variable=preMergelargeclusterET complete dim=0
#pragma HLS ARRAY_PARTITION variable=preMergesmallclusterET complete dim=0


  for(int teta = 0; teta < 17; teta++) {
#pragma HLS_UNROLL
    for(int tphi = 0; tphi < 4; tphi++) {
#pragma HLS_UNROLL
      preMergePeakEta[tphi][teta] = 999;
      preMergePeakPhi[tphi][teta] = 999;
      preMergelargeclusterET[tphi][teta] = 0;
      preMergesmallclusterET[tphi][teta] = 0;      
      
      if(!(ClusterFinder(crystals[tphi][teta], &preMergePeakEta[tphi][teta], &preMergePeakPhi[tphi][teta], &preMergelargeclusterET[tphi][teta], &preMergesmallclusterET[tphi][teta]))) 
	{
	  cerr << "ClusterFinder bombed" << endl;
	  return 1;
	}
    }
  }
  



  //merging
  for(int teta = 0; teta < 17; teta++) {
#pragma HLS_UNROLL
    for(int tphi = 0; tphi < 4; tphi++) {
#pragma HLS_UNROLL
      peakEta[tphi][teta] = preMergePeakEta[tphi][teta];
      peakPhi[tphi][teta] = preMergePeakPhi[tphi][teta];
      largeclusterET[tphi][teta] = preMergelargeclusterET[tphi][teta];
      smallclusterET[tphi][teta] = preMergesmallclusterET[tphi][teta];

      int ieta = -1;
      int iphi = -1;

      
      if(preMergePeakEta[tphi][teta]==0 && teta != 0) ieta = teta - 1;
      if(preMergePeakEta[tphi][teta]==4 && teta != 16) ieta = teta + 1;
      if(preMergePeakPhi[tphi][teta]==0 && tphi != 0) iphi = tphi - 1;
      if(preMergePeakPhi[tphi][teta]==4 && tphi != 3) iphi = tphi + 1;
      
      
      if(ieta >= 0 && ieta < 17 && iphi >= 0 && iphi < 4) {
	if((preMergePeakEta[tphi][teta]==preMergePeakEta[iphi][ieta]) || (preMergePeakPhi[tphi][teta]==preMergePeakPhi[iphi][ieta]))
	  {
	    if(preMergesmallclusterET[tphi][teta]>preMergesmallclusterET[iphi][ieta])
	      {
		peakEta[tphi][teta] = preMergePeakEta[tphi][teta];
		peakPhi[tphi][teta] = preMergePeakPhi[tphi][teta];
		peakEta[iphi][ieta] = 2;
		peakPhi[iphi][ieta] = 2;
		smallclusterET[tphi][teta] = preMergesmallclusterET[tphi][teta] + preMergesmallclusterET[iphi][ieta];
		largeclusterET[tphi][teta] = preMergelargeclusterET[tphi][teta] + preMergesmallclusterET[iphi][ieta];
		largeclusterET[iphi][ieta] = preMergelargeclusterET[iphi][ieta] - preMergesmallclusterET[iphi][ieta];
		smallclusterET[iphi][ieta] = 0;
		
	      }
	    else
	      {
		peakEta[iphi][ieta] = preMergePeakEta[iphi][ieta];
		    
		peakPhi[iphi][ieta] = preMergePeakPhi[iphi][ieta];
		peakEta[tphi][teta] = 2;
		peakPhi[tphi][teta] = 2;
		smallclusterET[iphi][ieta] = preMergesmallclusterET[iphi][ieta] + preMergesmallclusterET[tphi][teta];
		largeclusterET[iphi][ieta] = preMergelargeclusterET[iphi][ieta] + preMergesmallclusterET[tphi][teta];
		smallclusterET[tphi][teta] = 0;
		largeclusterET[tphi][teta] = preMergelargeclusterET[tphi][teta] - preMergesmallclusterET[tphi][teta];
	      }
	  }
	else{
	  peakEta[tphi][teta] = preMergePeakEta[tphi][teta];
	  peakPhi[tphi][teta] = preMergePeakPhi[tphi][teta];
	  largeclusterET[tphi][teta] = preMergelargeclusterET[tphi][teta];
	  smallclusterET[tphi][teta] = preMergesmallclusterET[tphi][teta];
	  
	  peakEta[iphi][ieta] = preMergePeakEta[iphi][ieta];
	  peakPhi[iphi][ieta] = preMergePeakPhi[iphi][ieta];
	  largeclusterET[iphi][ieta] = preMergelargeclusterET[iphi][ieta];
	  smallclusterET[iphi][ieta] = preMergesmallclusterET[iphi][ieta];
	  
	  
	}
	
	
      }
      
    }
      
    
  }
    

  


  return true;
}
