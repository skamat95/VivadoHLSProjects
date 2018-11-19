#include "ClusterFinder.hh"

#include <iostream>
using namespace std;

//For making the input map links and the input file
bool writeLinkMapRCT(uint16_t crystals[NCaloLayer1Eta][NCaloLayer1Phi][NCrystalsPerEtaPhi][NCrystalsPerEtaPhi],
        uint16_t peakEta[NCaloLayer1Eta][NCaloLayer1Phi],
        uint16_t peakPhi[NCaloLayer1Eta][NCaloLayer1Phi],
        uint16_t towerET[NCaloLayer1Eta][NCaloLayer1Phi],
        uint16_t clusterET[NCaloLayer1Eta][NCaloLayer1Phi],
		uint16_t SortedCluster_ET[Total_clusters],
		uint16_t SortedPeak_Eta[Total_clusters],
		uint16_t SortedPeak_Phi[Total_clusters]) {
  // This code is to write suitable mapping of inputs to signals in the CTP7_HLS project from Ales
  // Block 1 of User Code
  int iEta, iPhi, icrys1, icrys2, count, link, loBit, hiBit;
  static FILE *f1;
  f1 = fopen("link_data_map_RCT.txt","w");

  for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
		  for(icrys1 = 0; icrys1 < NCrystalsPerEtaPhi; icrys1++) {
			  for(icrys2 = 0; icrys2 < NCrystalsPerEtaPhi; icrys2++) {

				  fprintf(f1, "crystals_%d_%d_%d_%d : IN STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi, icrys1, icrys2);
			  }
		  }
	  }
  }

  for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
  	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
  		fprintf(f1, "peakEta_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);

  	  }
  }

  for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
    	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
    		fprintf(f1, "peakPhi_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);

    	  }
    }
  for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
      	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
      		fprintf(f1, "towerET_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);

      	  }
      }

  for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
        	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
        		fprintf(f1, "clusterET_%d_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);

        	  }
        }
  for(count = 0; count < Total_clusters; count++) {
          		fprintf(f1, "SortedCluster_ET_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", count);
          		fprintf(f1, "SortedPeak_Eta_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", count);
          		fprintf(f1, "SortedPeak_Phi_%d : OUT STD_LOGIC_VECTOR (15 downto 0);\n", count);
  	  }


  // Block 2

  for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
  	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
  		  for(icrys1 = 0; icrys1 < NCrystalsPerEtaPhi; icrys1++) {
  			  for(icrys2 = 0; icrys2 < NCrystalsPerEtaPhi; icrys2++) {

  				  fprintf(f1, "signal crystals_%d_%d_%d_%d : STD_LOGIC_VECTOR(15 DOWNTO 0);\n", iEta, iPhi, icrys1, icrys2);
  			  }
  		  }
  	  }
    }

    for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
    	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
    		fprintf(f1, "signal peakEta_%d_%d : STD_LOGIC_VECTOR(15 downto 0);\n", iEta, iPhi);

    	  }
    }

    for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
      	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
      		fprintf(f1, "signal peakPhi_%d_%d :STD_LOGIC_VECTOR(15 downto 0);\n", iEta, iPhi);

      	  }
      }
    for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
        	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
        		fprintf(f1, "signal towerET_%d_%d : STD_LOGIC_VECTOR(15 downto 0);\n", iEta, iPhi);

        	  }
        }

    for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
          	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
          		fprintf(f1, "signal clusterET_%d_%d : STD_LOGIC_VECTOR (15 downto 0);\n", iEta, iPhi);

          	  }
          }
    for(count = 0; count < Total_clusters; count++) {
            		fprintf(f1, "signal SortedCluster_ET_%d : STD_LOGIC_VECTOR (15 downto 0);\n", count);
            		fprintf(f1, "signal SortedPeak_Eta_%d : STD_LOGIC_VECTOR (15 downto 0);\n", count);
            		fprintf(f1, "signal SortedPeak_Phi_%d : STD_LOGIC_VECTOR (15 downto 0);\n", count);
    	  }




  // Block 3

    for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
    	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
    		  for(icrys1 = 0; icrys1 < NCrystalsPerEtaPhi; icrys1++) {
    			  for(icrys2 = 0; icrys2 < NCrystalsPerEtaPhi; icrys2++) {

    				  fprintf(f1, "crystals_%d_%d_%d_%d => crystals_%d_%d_%d_%d,\n", iEta, iPhi, icrys1, icrys2, iEta, iPhi, icrys1, icrys2);
    			  }
    		  }
    	  }
      }

      for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
      	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
      		fprintf(f1, "peakEta_%d_%d => peakEta_%d_%d,\n", iEta, iPhi, iEta, iPhi);

      	  }
      }

      for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
        	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
        		fprintf(f1, "peakPhi_%d_%d => peakPhi_%d_%d,\n", iEta, iPhi, iEta, iPhi);

        	  }
        }
      for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
          	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
          		fprintf(f1, "towerET_%d_%d => towerET_%d_%d,\n", iEta, iPhi, iEta, iPhi);

          	  }
          }

      for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
            	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
            		fprintf(f1, "clusterET_%d_%d => clusterET_%d_%d,\n", iEta, iPhi, iEta, iPhi);

            	  }
            }
      for(count = 0; count < 30; count++) {
              		fprintf(f1, "SortedCluster_ET_%d => SortedCluster_ET_%d,\n", count, count);
              		fprintf(f1, "SortedPeak_Eta_%d => SortedPeak_Eta_%d,\n", count, count);
              		fprintf(f1, "SortedPeak_Phi_%d => SortedPeak_Phi_%d,\n", count, count);
      	  }


  // Block 4

      int temp1 = 0;

      for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
      	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
      		  for(icrys1 = 0; icrys1 < NCrystalsPerEtaPhi; icrys1++) {
      			  for(icrys2 = 0; icrys2 < NCrystalsPerEtaPhi; icrys2++) {
      				// Each link can carry 192-bits, or 12x16-bits of data
      				    // Each iRgn needs 16 bits

      				    link = (temp1 / 12);
      				    loBit = (temp1 % 12) * 16;
      				    hiBit = loBit + 15;

      				  fprintf(f1, "crystals_%d_%d_%d_%d <= s_INPUT_LINK_ARR( %d )(%d downto %d);\n", iEta, iPhi, icrys1, icrys2, link, hiBit, loBit);
      				  temp1++;
      			  }
      		  }
      	  }
        }

      //output links
      int temp2 = 0;
        for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
        	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
        		link = (temp2 / 12);
				loBit = (temp2 % 12) * 16;
				hiBit = loBit + 15;
        		fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= peakEta_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
        		temp2++;
        	  }
        }

        for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
          	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
          		link = (temp2 / 12);
				loBit = (temp2 % 12) * 16;
				hiBit = loBit + 15;
          		fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= peakPhi_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
          		temp2++;
          	  }
          }
        for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
            	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
            		link = (temp2 / 12);
					loBit = (temp2 % 12) * 16;
					hiBit = loBit + 15;
            		fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= towerET_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
            		temp2++;
            	  }
            }

        for(iEta = 0; iEta < NCaloLayer1Eta; iEta++) {
              	  for(iPhi = 0; iPhi < NCaloLayer1Phi; iPhi++) {
              		link = (temp2 / 12);
					loBit = (temp2 % 12) * 16;
					hiBit = loBit + 15;
              		fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= clusterET_%d_%d;\n", link, hiBit, loBit, iEta, iPhi);
              		temp2++;
              	  }
              }


        for(count = 0; count < Total_clusters; count++) {

			link = (temp2 / 12);
			loBit = (temp2 % 12) * 16;
			hiBit = loBit + 15;
			fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= SortedCluster_ET_%d;\n", link, hiBit, loBit, count);
			temp2++;
		}
		for(count = 0; count < Total_clusters; count++) {

				link = (temp2 / 12);
				loBit = (temp2 % 12) * 16;
				hiBit = loBit + 15;

				fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= SortedPeak_Eta_%d;\n", link, hiBit, loBit, count);

				temp2++;
			  }
		for(count = 0; count < Total_clusters; count++) {

				link = (temp2 / 12);
				loBit = (temp2 % 12) * 16;
				hiBit = loBit + 15;
				fprintf(f1, "s_OUTPUT_LINK_ARR( %d )(%d downto %d) <= SortedPeak_Phi_%d;\n", link, hiBit, loBit, count);
				temp2++;
			  }


  return true;
}

int main(int argc, char **argv) {
  uint16_t crystals[17][4][5][5];
  for(int tEta = 0; tEta < 17; tEta++) {
    for(int tPhi = 0; tPhi < 4; tPhi++) {
      for(int cEta = 0; cEta < 5; cEta++) {
        for(int cPhi = 0; cPhi < 5; cPhi++) {
          crystals[tEta][tPhi][cEta][cPhi] = 0;
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
          crystals[tEta][tPhi][cEta][cPhi] = (clusters[cluster] * 0.9);
        }
        else {
          if(ntEta >= 0 && ntEta < 17 && ntPhi >= 0 && ntPhi < 4)
            crystals[ntEta][ntPhi][ncEta][ncPhi] = (clusters[cluster] * 0.1 / 8.);
        }
      }
    }

    totalET += clusters[cluster];
  }
  cout << "Total generated ET = " << totalET << endl;
  uint16_t totalDeposited = 0;
  for(int tEta = 0; tEta < 17; tEta++) {
    for(int tPhi = 0; tPhi < 4; tPhi++) {
      for(int cEta = 0; cEta < 5; cEta++) {
        for(int cPhi = 0; cPhi < 5; cPhi++) {
	  //std::cout<<"tEta/tPhi/cEta/cPhi/crystalet/"<<tEta<<"/"<<tPhi<<"/"<<cEta<<"/"<<cPhi<<"/"<<crystals[tEta][tPhi][cEta][cPhi]<<endl;
		  
          totalDeposited += crystals[tEta][tPhi][cEta][cPhi];
	    }
      }
    }
  }
  cout << "Total deposited ET = " << totalDeposited << endl;
  uint16_t peakEta[17][4];
  uint16_t peakPhi[17][4];
  uint16_t largeClusterET[17][4];
  uint16_t smallClusterET[17][4];
  uint16_t sortedCluster_ET[30];
  uint16_t sortedPeak_Eta[30];
  uint16_t sortedPeak_Phi[30];
  uint16_t totalCardET = 0;

  //Generating map link file
  bool success_link_map = false;
  success_link_map = writeLinkMapRCT(crystals, peakEta, peakPhi, largeClusterET, smallClusterET, sortedCluster_ET, sortedPeak_Eta, sortedPeak_Phi);


  if(getClustersInCard(crystals, peakEta, peakPhi, largeClusterET, smallClusterET,sortedCluster_ET,sortedPeak_Eta,sortedPeak_Phi)) {
    cout << "From the simulation: " << endl;
    cout << "tEta\ttPhi\tpeakEta\tpeakPhi\tlargeClusterET\tsmallClusterET\t" << endl;
    for(int tEta = 0; tEta < 17; tEta++) {
      for(int tPhi = 0; tPhi < 4; tPhi++) {
        if(largeClusterET[tEta][tPhi] > 0) 
          cout << tEta
               << "\t" << tPhi
               << "\t" << peakEta[tEta][tPhi]
               << "\t" << peakPhi[tEta][tPhi]
               << "\t" << largeClusterET[tEta][tPhi]
               << "\t" << smallClusterET[tEta][tPhi]
	       <<"\t"<<endl;
        totalCardET += largeClusterET[tEta][tPhi];
      }
    }
    cout << "Total card ET = " << totalCardET << endl;
  }
  else {
    cout << "ClusterFinder failed" << endl;
    //cout << "Hi dinho"
    return 1;
  }
     
  return 0;
}

