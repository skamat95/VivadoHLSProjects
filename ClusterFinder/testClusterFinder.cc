#include "ClusterFinder.hh"
#include "TowerFinder.hh"

#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  uint16_t crystals[4][17][5][5];
  for(int tPhi = 0; tPhi < 4; tPhi++) {
    for(int tEta = 0; tEta < 17; tEta++) {
      for(int cEta = 0; cEta < 5; cEta++) {
        for(int cPhi = 0; cPhi < 5; cPhi++) {
          crystals[tPhi][tEta][cEta][cPhi] = 0;
        }
      }
    }
  }
  double totalET = 0;
  double clusters[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 111};
  cout << "Generated clusters: " << endl;
  cout << "tEta\ttPhi\tcEta\tcPhi\tclusterET" << endl;
  for(int cluster = 0; cluster < 10; cluster++) {
    // Crude simulation of dispersal of cluster ET for fun around some location
    int clusterET = clusters[cluster];
    int tEta = clusterET % 17;
    int tPhi = clusterET % 4;
    int cEta = (tPhi * clusterET) % 5;
    int cPhi = (tEta * clusterET) % 5;
    cout << tEta
         << "\t" << tPhi
         << "\t" << cEta
         << "\t" << cPhi
         << "\t" << clusters[cluster] << endl;
    for(int dEta = -1; dEta <= 1; dEta++) {
      for(int dPhi = -1; dPhi <= 1; dPhi++) {
        int ncEta = cEta + dEta;
        int ncPhi = cPhi + dPhi;
        // Start within the tower boundary
        int ntEta = tEta;
        int ntPhi = tPhi;
        // Adjust neighbor trigger tower as needed
        if(ncEta < 0) {ncEta = 4; ntEta = tEta - 1;}
        else if(ncEta > 4) {ncEta = 0; ntEta = tEta + 1;}
        if(ncPhi < 0) {ncPhi = 4; ntPhi = tPhi - 1;}
        else if(ncPhi > 4) {ncPhi = 0; ntPhi = tPhi + 1;}
        // Ignore spill-overs outside the card, defering to next layer
        if(dEta == 0 && dPhi == 0) {
          crystals[tPhi][tEta][cEta][cPhi] = (clusters[cluster] * 0.9);
        }
        else {
          if(ntEta >= 0 && ntEta < 17 && ntPhi >= 0 && ntPhi < 4)
            crystals[ntPhi][ntEta][ncEta][ncPhi] = (clusters[cluster] * 0.1 / 8.);
        }
      }
    }
    totalET += clusters[cluster];
  }
  cout << "Total generated ET = " << totalET << endl;
  uint16_t totalDeposited = 0;
  for(int tPhi = 0; tPhi < 4; tPhi++) {
    for(int tEta = 0; tEta < 17; tEta++) {
      for(int cEta = 0; cEta < 5; cEta++) {
        for(int cPhi = 0; cPhi < 5; cPhi++) {
          totalDeposited += crystals[tPhi][tEta][cEta][cPhi];
	}
      }
    }
  }
  cout << "Total deposited ET = " << totalDeposited << endl;
  uint16_t peakEta[4][17];
  uint16_t peakPhi[4][17];
  uint16_t largeClusterET[4][17];
  uint16_t smallClusterET[4][17];
  uint16_t totalCardET = 0;
  if(TowerFinder(crystals,peakEta, peakPhi, largeClusterET, smallClusterET)) {
    cout << "From the simulation: " << endl;
    cout << "tEta\ttPhi\tpeakEta\tpeakPhi\tlargeClusterET\tsmallClusterET" << endl;
      for(int tEta = 0; tEta < 17; tEta++) {
	for(int tPhi = 0; tPhi < 4; tPhi++) {
	  if(largeClusterET[tPhi][tEta] > 0) 
          cout << tEta
               << "\t" << tPhi
               << "\t" << peakEta[tPhi][tEta]
               << "\t" << peakPhi[tPhi][tEta]
               << "\t" << largeClusterET[tPhi][tEta]
               << "\t" << smallClusterET[tPhi][tEta] << endl;
        totalCardET += largeClusterET[tPhi][tEta];
      }
    }
    cout << "Total card ET = " << totalCardET << endl;
  }
  else {
    cout << "ClusterFinder failed" << endl;
    return 1;
  }
     
  return 0;
}
