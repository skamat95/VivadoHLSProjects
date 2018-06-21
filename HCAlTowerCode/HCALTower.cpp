#include "HCALTower.h"
void bitonic_1_16(uint16_t Cluster_1_Deposits[16], uint16_t Cluster_1_Eta[16], uint16_t Cluster_1_Phi[16])
{// sorting blocks of size 16
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<8;i++)
  {
  #pragma HLS unroll
  if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+8])
    {
      temp=Cluster_1_Deposits[i+8];
      Cluster_1_Deposits[i+8]=Cluster_1_Deposits[i];
      Cluster_1_Deposits[i]=temp;
      temp=Cluster_1_Eta[i];
        Cluster_1_Eta[i]=Cluster_1_Eta[i+8];
        Cluster_1_Eta[i+8]=temp;
        temp=Cluster_1_Phi[i];
        Cluster_1_Phi[i]=Cluster_1_Phi[i+8];
        Cluster_1_Phi[i+8]=temp;
    }

    }

  
   for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+4])
    {
      temp=Cluster_1_Deposits[i+4];
      Cluster_1_Deposits[i+4]=Cluster_1_Deposits[i];
      Cluster_1_Deposits[i]=temp;
      temp=Cluster_1_Eta[i];
        Cluster_1_Eta[i]=Cluster_1_Eta[i+4];
        Cluster_1_Eta[i+4]=temp;
        temp=Cluster_1_Phi[i];
        Cluster_1_Phi[i]=Cluster_1_Phi[i+4];
        Cluster_1_Phi[i+4]=temp;
    }
    }
   for(int i=8;i<12;i++)
  {
  #pragma HLS unroll
  if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+4])
    {
      temp=Cluster_1_Deposits[i+4];
      Cluster_1_Deposits[i+4]=Cluster_1_Deposits[i];
      Cluster_1_Deposits[i]=temp;
      temp=Cluster_1_Eta[i];
        Cluster_1_Eta[i]=Cluster_1_Eta[i+4];
        Cluster_1_Eta[i+4]=temp;
        temp=Cluster_1_Phi[i];
        Cluster_1_Phi[i]=Cluster_1_Phi[i+4];
        Cluster_1_Phi[i+4]=temp;
    }
    }
  

  for(int i=0;i<13;i=i+4)
  {
  #pragma HLS unroll
  if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+2])
    {
      temp=Cluster_1_Deposits[i+2];
      Cluster_1_Deposits[i+2]=Cluster_1_Deposits[i];
      Cluster_1_Deposits[i]=temp;
      temp=Cluster_1_Eta[i];
          Cluster_1_Eta[i]=Cluster_1_Eta[i+2];
          Cluster_1_Eta[i+2]=temp;
          temp=Cluster_1_Phi[i];
          Cluster_1_Phi[i]=Cluster_1_Phi[i+2];
          Cluster_1_Phi[i+2]=temp;
    }

    if(Cluster_1_Deposits[i+1]<Cluster_1_Deposits[i+3])
    {
      temp=Cluster_1_Deposits[i+3];
      Cluster_1_Deposits[i+3]=Cluster_1_Deposits[i+1];
      Cluster_1_Deposits[i+1]=temp;
       temp=Cluster_1_Eta[i+1];
              Cluster_1_Eta[i+1]=Cluster_1_Eta[i+3];
              Cluster_1_Eta[i+3]=temp;
              temp=Cluster_1_Phi[i+1];
              Cluster_1_Phi[i+1]=Cluster_1_Phi[i+3];
              Cluster_1_Phi[i+3]=temp;
    }
    }
  
 
   

  for(int i=0;i<15;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+1])
    {
      temp=Cluster_1_Deposits[i+1];
      Cluster_1_Deposits[i+1]=Cluster_1_Deposits[i];
      Cluster_1_Deposits[i]=temp;
       temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+1];
              Cluster_1_Eta[i+1]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+1];
              Cluster_1_Phi[i+1]=temp;
    }

    }
 


  }

void bitonic_1_8(uint16_t Cluster_1_Deposits[16], uint16_t Cluster_1_Eta[16], uint16_t Cluster_1_Phi[16])
{// sorting blocks of size 8
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<4;i++)
  {
    #pragma HLS unroll
    if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+4])
      {
        temp=Cluster_1_Deposits[i+4];
        Cluster_1_Deposits[i+4]=Cluster_1_Deposits[i];
        Cluster_1_Deposits[i]=temp;
        temp=Cluster_1_Eta[i];
        Cluster_1_Eta[i]=Cluster_1_Eta[i+4];
        Cluster_1_Eta[i+4]=temp;
        temp=Cluster_1_Phi[i];
        Cluster_1_Phi[i]=Cluster_1_Phi[i+4];
        Cluster_1_Phi[i+4]=temp;
      }
  }
  for(int i=8;i<12;i++)
  {
    #pragma HLS unroll
    if(Cluster_1_Deposits[i]>Cluster_1_Deposits[i+4])
      {
        temp=Cluster_1_Deposits[i+4];
        Cluster_1_Deposits[i+4]=Cluster_1_Deposits[i];
        Cluster_1_Deposits[i]=temp;
        temp=Cluster_1_Eta[i];
        Cluster_1_Eta[i]=Cluster_1_Eta[i+4];
        Cluster_1_Eta[i+4]=temp;
        temp=Cluster_1_Phi[i];
        Cluster_1_Phi[i]=Cluster_1_Phi[i+4];
        Cluster_1_Phi[i+4]=temp;
      }
  }
 

  for(int i=0;i<5;i=i+4)
  {
    #pragma HLS unroll
    if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+2])
      {
        temp=Cluster_1_Deposits[i+2];
        Cluster_1_Deposits[i+2]=Cluster_1_Deposits[i];
        Cluster_1_Deposits[i]=temp;
        temp=Cluster_1_Eta[i+2];
        Cluster_1_Eta[i+2]=Cluster_1_Eta[i];
        Cluster_1_Eta[i]=temp;
        temp=Cluster_1_Phi[i+2];
        Cluster_1_Phi[i+2]=Cluster_1_Phi[i];
        Cluster_1_Phi[i]=temp;
      }
    if(Cluster_1_Deposits[i+1]<Cluster_1_Deposits[i+3])
      {
        temp=Cluster_1_Deposits[i+3];
        Cluster_1_Deposits[i+3]=Cluster_1_Deposits[i+1];
        Cluster_1_Deposits[i+1]=temp;
          temp=Cluster_1_Eta[i+1];
        Cluster_1_Eta[i+1]=Cluster_1_Eta[i+3];
        Cluster_1_Eta[i+3]=temp;
        temp=Cluster_1_Phi[i+1];
        Cluster_1_Phi[i+1]=Cluster_1_Phi[i+3];
        Cluster_1_Phi[i+3]=temp;
      }
  }
  for(int i=8;i<13;i=i+4)
  {
    #pragma HLS unroll
    if(Cluster_1_Deposits[i]>Cluster_1_Deposits[i+2])
      {
        temp=Cluster_1_Deposits[i+2];
        Cluster_1_Deposits[i+2]=Cluster_1_Deposits[i];
        Cluster_1_Deposits[i]=temp;
        temp=Cluster_1_Eta[i+2];
        Cluster_1_Eta[i+2]=Cluster_1_Eta[i];
        Cluster_1_Eta[i]=temp;
        temp=Cluster_1_Phi[i+2];
        Cluster_1_Phi[i+2]=Cluster_1_Phi[i];
        Cluster_1_Phi[i]=temp;
      }
    if(Cluster_1_Deposits[i+1]>Cluster_1_Deposits[i+3])
      {
        temp=Cluster_1_Deposits[i+3];
        Cluster_1_Deposits[i+3]=Cluster_1_Deposits[i+1];
        Cluster_1_Deposits[i+1]=temp;
         temp=Cluster_1_Eta[i+1];
        Cluster_1_Eta[i+1]=Cluster_1_Eta[i+3];
        Cluster_1_Eta[i+3]=temp;
        temp=Cluster_1_Phi[i+1];
        Cluster_1_Phi[i+1]=Cluster_1_Phi[i+3];
        Cluster_1_Phi[i+3]=temp;
      }
  }
  
  for(int i=0;i<7;i=i+2)
  {
    #pragma HLS unroll
    if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+1])
      {
        temp=Cluster_1_Deposits[i+1];
        Cluster_1_Deposits[i+1]=Cluster_1_Deposits[i];
        Cluster_1_Deposits[i]=temp;
          temp=Cluster_1_Eta[i];
          Cluster_1_Eta[i]=Cluster_1_Eta[i+1];
          Cluster_1_Eta[i+1]=temp;
          temp=Cluster_1_Phi[i];
          Cluster_1_Phi[i]=Cluster_1_Phi[i+1];
          Cluster_1_Phi[i+1]=temp;
      }
  }
  for(int i=8;i<15;i=i+2)
  {
    #pragma HLS unroll
    if(Cluster_1_Deposits[i]>Cluster_1_Deposits[i+1])
      {
        temp=Cluster_1_Deposits[i+1];
        Cluster_1_Deposits[i+1]=Cluster_1_Deposits[i];
        Cluster_1_Deposits[i]=temp;
          temp=Cluster_1_Eta[i];
          Cluster_1_Eta[i]=Cluster_1_Eta[i+1];
          Cluster_1_Eta[i+1]=temp;
          temp=Cluster_1_Phi[i];
          Cluster_1_Phi[i]=Cluster_1_Phi[i+1];
          Cluster_1_Phi[i+1]=temp;
      }
  }
 bitonic_1_16(Cluster_1_Deposits,Cluster_1_Eta,Cluster_1_Phi);
}
void bitonic_1_4(uint16_t Cluster_1_Deposits[16], uint16_t Cluster_1_Eta[16], uint16_t Cluster_1_Phi[16])
{
  int temp;
// #pragma HLS dataflow
// comparators in blocks of 4
  for(int i=0;i<2;i++)
  {
    #pragma HLS unroll
      if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+2])
              {temp=Cluster_1_Deposits[i];
              Cluster_1_Deposits[i]=Cluster_1_Deposits[i+2];
              Cluster_1_Deposits[i+2]=temp;
               temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+2];
              Cluster_1_Eta[i+2]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+2];
              Cluster_1_Phi[i+2]=temp;
              }
  }
  for(int i=4;i<6;i++)
  {
#pragma HLS unroll
    if(Cluster_1_Deposits[i]>Cluster_1_Deposits[i+2])
              {temp=Cluster_1_Deposits[i];
              Cluster_1_Deposits[i]=Cluster_1_Deposits[i+2];
              Cluster_1_Deposits[i+2]=temp;
               temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+2];
              Cluster_1_Eta[i+2]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+2];
              Cluster_1_Phi[i+2]=temp;
              }
  }
  for(int i=8;i<10;i++)
  {
#pragma HLS unroll
      if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+2])
              {temp=Cluster_1_Deposits[i];
              Cluster_1_Deposits[i]=Cluster_1_Deposits[i+2];
              Cluster_1_Deposits[i+2]=temp;
               temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+2];
              Cluster_1_Eta[i+2]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+2];
              Cluster_1_Phi[i+2]=temp;
              }
  }
  for(int i=12;i<14;i++)
  {
#pragma HLS unroll
      if(Cluster_1_Deposits[i]>Cluster_1_Deposits[i+2])
              {temp=Cluster_1_Deposits[i];
              Cluster_1_Deposits[i]=Cluster_1_Deposits[i+2];
              Cluster_1_Deposits[i+2]=temp;
               temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+2];
              Cluster_1_Eta[i+2]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+2];
              Cluster_1_Phi[i+2]=temp;
              }
  }
  
  for(int i=0;i<3;i=i+2)
  {
  #pragma HLS unroll
    if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+1])
              {temp=Cluster_1_Deposits[i];
              Cluster_1_Deposits[i]=Cluster_1_Deposits[i+1];
              Cluster_1_Deposits[i+1]=temp;
                temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+1];
              Cluster_1_Eta[i+1]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+1];
              Cluster_1_Phi[i+1]=temp;
              }
  }
  for(int i=4;i<7;i=i+2)
  {
  #pragma HLS unroll
    if(Cluster_1_Deposits[i]>Cluster_1_Deposits[i+1])
              {temp=Cluster_1_Deposits[i];
              Cluster_1_Deposits[i]=Cluster_1_Deposits[i+1];
              Cluster_1_Deposits[i+1]=temp;
                temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+1];
              Cluster_1_Eta[i+1]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+1];
              Cluster_1_Phi[i+1]=temp;
              }
  }
  for(int i=8;i<11;i=i+2)
  {
  #pragma HLS unroll
    if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+1])
              {temp=Cluster_1_Deposits[i];
              Cluster_1_Deposits[i]=Cluster_1_Deposits[i+1];
              Cluster_1_Deposits[i+1]=temp;
                temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+1];
              Cluster_1_Eta[i+1]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+1];
              Cluster_1_Phi[i+1]=temp;
              }
  }
  for(int i=12;i<15;i=i+2)
  {
  #pragma HLS unroll
    if(Cluster_1_Deposits[i]>Cluster_1_Deposits[i+1])
              {temp=Cluster_1_Deposits[i];
              Cluster_1_Deposits[i]=Cluster_1_Deposits[i+1];
              Cluster_1_Deposits[i+1]=temp;
                temp=Cluster_1_Eta[i];
              Cluster_1_Eta[i]=Cluster_1_Eta[i+1];
              Cluster_1_Eta[i+1]=temp;
              temp=Cluster_1_Phi[i];
              Cluster_1_Phi[i]=Cluster_1_Phi[i+1];
              Cluster_1_Phi[i+1]=temp;
              }
  }
  
  bitonic_1_8(Cluster_1_Deposits,Cluster_1_Eta,Cluster_1_Phi);

}
void bitonic32(uint16_t ClusterDeposits[32], uint16_t ClusterEta[32], uint16_t ClusterPhi[32])
{// sorting blocks of size 32
  int temp;
// #pragma HLS dataflow
for(int i=0;i<16;i++)
{
#pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+16])
    {
      temp=ClusterDeposits[i+16];
      ClusterDeposits[i+16]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+16];
        ClusterEta[i+16]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+16];
        ClusterPhi[i+16]=temp;
    }
  }

  for(int i=0;i<8;i++)
  {
#pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+8])
        {
          temp=ClusterDeposits[i+8];
          ClusterDeposits[i+8]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+8];
        ClusterEta[i+8]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+8];
        ClusterPhi[i+8]=temp;
        }
  }
  for(int i=16;i<24;i++)
    {
  #pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+8])
          {
            temp=ClusterDeposits[i+8];
            ClusterDeposits[i+8]=ClusterDeposits[i];
            ClusterDeposits[i]=temp;
            temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+8];
        ClusterEta[i+8]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+8];
        ClusterPhi[i+8]=temp;
          }
    }



 for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }
 for(int i=8;i<12;i++)
      {
      #pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+4])
        {
          temp=ClusterDeposits[i+4];
          ClusterDeposits[i+4]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
        }
        }
 for(int i=16;i<20;i++)
      {
      #pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+4])
        {
          temp=ClusterDeposits[i+4];
          ClusterDeposits[i+4]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
        }
        }
 for(int i=24;i<28;i++)
      {
      #pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+4])
        {
          temp=ClusterDeposits[i+4];
          ClusterDeposits[i+4]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
        }
        }


 for(int i=0;i<29;i=i+4)
            {
            #pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+2])
          {
              temp=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=ClusterDeposits[i];
              ClusterDeposits[i]=temp;
               temp=ClusterEta[i];
                ClusterEta[i]=ClusterEta[i+2];
                ClusterEta[i+2]=temp;
                temp=ClusterPhi[i];
                ClusterPhi[i]=ClusterPhi[i+2];
                ClusterPhi[i+2]=temp;
          }
          if(ClusterDeposits[i+1]<ClusterDeposits[i+3])
          {
              temp=ClusterDeposits[i+3];
              ClusterDeposits[i+3]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
              temp=ClusterEta[i+1];
               ClusterEta[i+1]=ClusterEta[i+3];
               ClusterEta[i+3]=temp;
               temp=ClusterPhi[i+1];
               ClusterPhi[i+1]=ClusterPhi[i+3];
               ClusterPhi[i+3]=temp;
          }
          }


     for(int i=0;i<31;i=i+2)
      {
      #pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+1])
        {
          temp=ClusterDeposits[i+1];
          ClusterDeposits[i+1]=ClusterDeposits[i];
          ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
        }
      }

  }  
void bitonic16(uint16_t ClusterDeposits[32], uint16_t ClusterEta[32], uint16_t ClusterPhi[32])
{// sorting blocks of size 16
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<8;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+8])
    {
      temp=ClusterDeposits[i+8];
      ClusterDeposits[i+8]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+8];
        ClusterEta[i+8]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+8];
        ClusterPhi[i+8]=temp;
    }

    }

  for(int i=16;i<24;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+8])
    {
      temp=ClusterDeposits[i+8];
      ClusterDeposits[i+8]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+8];
        ClusterEta[i+8]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+8];
        ClusterPhi[i+8]=temp;
    }

    }
   for(int i=0;i<4;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }
   for(int i=8;i<12;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }
   for(int i=16;i<20;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }
  for(int i=24;i<28;i++)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+4])
    {
      temp=ClusterDeposits[i+4];
      ClusterDeposits[i+4]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
    }
    }

  for(int i=0;i<13;i=i+4)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]<ClusterDeposits[i+2])
    {
      temp=ClusterDeposits[i+2];
      ClusterDeposits[i+2]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+2];
          ClusterEta[i+2]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+2];
          ClusterPhi[i+2]=temp;
    }

    if(ClusterDeposits[i+1]<ClusterDeposits[i+3])
    {
      temp=ClusterDeposits[i+3];
      ClusterDeposits[i+3]=ClusterDeposits[i+1];
      ClusterDeposits[i+1]=temp;
       temp=ClusterEta[i+1];
              ClusterEta[i+1]=ClusterEta[i+3];
              ClusterEta[i+3]=temp;
              temp=ClusterPhi[i+1];
              ClusterPhi[i+1]=ClusterPhi[i+3];
              ClusterPhi[i+3]=temp;
    }
    }
  for(int i=16;i<29;i=i+4)
  {
  #pragma HLS unroll
  if(ClusterDeposits[i]>ClusterDeposits[i+2])
    {
      temp=ClusterDeposits[i+2];
      ClusterDeposits[i+2]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
      temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+2];
          ClusterEta[i+2]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+2];
          ClusterPhi[i+2]=temp;
    }

    if(ClusterDeposits[i+1]>ClusterDeposits[i+3])
    {
      temp=ClusterDeposits[i+3];
      ClusterDeposits[i+3]=ClusterDeposits[i+1];
      ClusterDeposits[i+1]=temp;
       temp=ClusterEta[i+1];
              ClusterEta[i+1]=ClusterEta[i+3];
              ClusterEta[i+3]=temp;
              temp=ClusterPhi[i+1];
              ClusterPhi[i+1]=ClusterPhi[i+3];
              ClusterPhi[i+3]=temp;
    }
    }
 
   

  for(int i=0;i<15;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if(ClusterDeposits[i]<ClusterDeposits[i+1])
    {
      temp=ClusterDeposits[i+1];
      ClusterDeposits[i+1]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
       temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
    }

    }
  for(int i=16;i<31;i=i+2)
  {
  #pragma HLS unroll//may be faster if split into two loops
  if(ClusterDeposits[i]>ClusterDeposits[i+1])
    {
      temp=ClusterDeposits[i+1];
      ClusterDeposits[i+1]=ClusterDeposits[i];
      ClusterDeposits[i]=temp;
       temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
    }

    }


bitonic32(ClusterDeposits,ClusterEta,ClusterPhi);
  }

void bitonic8(uint16_t ClusterDeposits[32], uint16_t ClusterEta[32], uint16_t ClusterPhi[32])
{// sorting blocks of size 8
  int temp;
// #pragma HLS dataflow
  for(int i=0;i<4;i++)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+4])
      {
        temp=ClusterDeposits[i+4];
        ClusterDeposits[i+4]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
      }
  }
  for(int i=8;i<12;i++)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+4])
      {
        temp=ClusterDeposits[i+4];
        ClusterDeposits[i+4]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
      }
  }
  for(int i=16;i<20;i++)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+4])
      {
        temp=ClusterDeposits[i+4];
        ClusterDeposits[i+4]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
      }
  }
  for(int i=24;i<28;i++)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+4])
      {
        temp=ClusterDeposits[i+4];
        ClusterDeposits[i+4]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i];
        ClusterEta[i]=ClusterEta[i+4];
        ClusterEta[i+4]=temp;
        temp=ClusterPhi[i];
        ClusterPhi[i]=ClusterPhi[i+4];
        ClusterPhi[i+4]=temp;
      }
  }


  for(int i=0;i<5;i=i+4)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+2])
      {
        temp=ClusterDeposits[i+2];
        ClusterDeposits[i+2]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i+2];
        ClusterEta[i+2]=ClusterEta[i];
        ClusterEta[i]=temp;
        temp=ClusterPhi[i+2];
        ClusterPhi[i+2]=ClusterPhi[i];
        ClusterPhi[i]=temp;
      }
    if(ClusterDeposits[i+1]<ClusterDeposits[i+3])
      {
        temp=ClusterDeposits[i+3];
        ClusterDeposits[i+3]=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=temp;
          temp=ClusterEta[i+1];
        ClusterEta[i+1]=ClusterEta[i+3];
        ClusterEta[i+3]=temp;
        temp=ClusterPhi[i+1];
        ClusterPhi[i+1]=ClusterPhi[i+3];
        ClusterPhi[i+3]=temp;
      }
  }
  for(int i=8;i<13;i=i+4)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+2])
      {
        temp=ClusterDeposits[i+2];
        ClusterDeposits[i+2]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i+2];
        ClusterEta[i+2]=ClusterEta[i];
        ClusterEta[i]=temp;
        temp=ClusterPhi[i+2];
        ClusterPhi[i+2]=ClusterPhi[i];
        ClusterPhi[i]=temp;
      }
    if(ClusterDeposits[i+1]>ClusterDeposits[i+3])
      {
        temp=ClusterDeposits[i+3];
        ClusterDeposits[i+3]=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=temp;
         temp=ClusterEta[i+1];
        ClusterEta[i+1]=ClusterEta[i+3];
        ClusterEta[i+3]=temp;
        temp=ClusterPhi[i+1];
        ClusterPhi[i+1]=ClusterPhi[i+3];
        ClusterPhi[i+3]=temp;
      }
  }
  for(int i=16;i<21;i=i+4)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+2])
      {
        temp=ClusterDeposits[i+2];
        ClusterDeposits[i+2]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i+2];
        ClusterEta[i+2]=ClusterEta[i];
        ClusterEta[i]=temp;
        temp=ClusterPhi[i+2];
        ClusterPhi[i+2]=ClusterPhi[i];
        ClusterPhi[i]=temp;
      }
    if(ClusterDeposits[i+1]<ClusterDeposits[i+3])
      {
        temp=ClusterDeposits[i+3];
        ClusterDeposits[i+3]=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=temp;
         temp=ClusterEta[i+1];
        ClusterEta[i+1]=ClusterEta[i+3];
        ClusterEta[i+3]=temp;
        temp=ClusterPhi[i+1];
        ClusterPhi[i+1]=ClusterPhi[i+3];
        ClusterPhi[i+3]=temp;
      }
  }
  for(int i=24;i<29;i=i+4)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+2])
      {
        temp=ClusterDeposits[i+2];
        ClusterDeposits[i+2]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
        temp=ClusterEta[i+2];
        ClusterEta[i+2]=ClusterEta[i];
        ClusterEta[i]=temp;
        temp=ClusterPhi[i+2];
        ClusterPhi[i+2]=ClusterPhi[i];
        ClusterPhi[i]=temp;
      }
      
    if(ClusterDeposits[i+1]>ClusterDeposits[i+3])
      {
        temp=ClusterDeposits[i+3];
        ClusterDeposits[i+3]=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=temp;
        temp=ClusterEta[i+1];
        ClusterEta[i+1]=ClusterEta[i+3];
        ClusterEta[i+3]=temp;
        temp=ClusterPhi[i+1];
        ClusterPhi[i+1]=ClusterPhi[i+3];
        ClusterPhi[i+3]=temp;
      }
      
  }


  for(int i=0;i<7;i=i+2)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
      {
        temp=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+1];
          ClusterEta[i+1]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+1];
          ClusterPhi[i+1]=temp;
      }
  }
  for(int i=8;i<15;i=i+2)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
      {
        temp=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+1];
          ClusterEta[i+1]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+1];
          ClusterPhi[i+1]=temp;
      }
  }
  for(int i=16;i<23;i=i+2)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
      {
        temp=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
          temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+1];
          ClusterEta[i+1]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+1];
          ClusterPhi[i+1]=temp;
      }
  }
  for(int i=24;i<31;i=i+2)
  {
    #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
      {
        temp=ClusterDeposits[i+1];
        ClusterDeposits[i+1]=ClusterDeposits[i];
        ClusterDeposits[i]=temp;
         temp=ClusterEta[i];
          ClusterEta[i]=ClusterEta[i+1];
          ClusterEta[i+1]=temp;
          temp=ClusterPhi[i];
          ClusterPhi[i]=ClusterPhi[i+1];
          ClusterPhi[i+1]=temp;
      }
  }
 
bitonic16(ClusterDeposits,ClusterEta,ClusterPhi);
}
void bitonic4(uint16_t ClusterDeposits[32], uint16_t ClusterEta[32], uint16_t ClusterPhi[32])
{
  int temp;
// #pragma HLS dataflow
// comparators in blocks of 4
  for(int i=0;i<2;i++)
  {
    #pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=4;i<6;i++)
  {
#pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=8;i<10;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=12;i<14;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=16;i<18;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=20;i<22;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=24;i<26;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]<ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
  for(int i=28;i<30;i++)
  {
#pragma HLS unroll
      if(ClusterDeposits[i]>ClusterDeposits[i+2])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+2];
              ClusterDeposits[i+2]=temp;
               temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+2];
              ClusterEta[i+2]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+2];
              ClusterPhi[i+2]=temp;
              }
  }
 
  for(int i=0;i<3;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=4;i<7;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=8;i<11;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=12;i<15;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=16;i<19;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=20;i<23;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=24;i<27;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]<ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  for(int i=28;i<31;i=i+2)
  {
  #pragma HLS unroll
    if(ClusterDeposits[i]>ClusterDeposits[i+1])
              {temp=ClusterDeposits[i];
              ClusterDeposits[i]=ClusterDeposits[i+1];
              ClusterDeposits[i+1]=temp;
                temp=ClusterEta[i];
              ClusterEta[i]=ClusterEta[i+1];
              ClusterEta[i+1]=temp;
              temp=ClusterPhi[i];
              ClusterPhi[i]=ClusterPhi[i+1];
              ClusterPhi[i+1]=temp;
              }
  }
  
  bitonic8(ClusterDeposits,ClusterEta,ClusterPhi);

}
void getTowerPeaks3x4(uint16_t towerETRegions[3][4],uint16_t cEta[5],
                        uint16_t cPhi[5])
{
  int temp;// temporary copying variable
#pragma HLS PIPELINE II=6
 uint16_t Cluster_1_Deposits[16];
  uint16_t Cluster_1_Eta[16];
  uint16_t Cluster_1_Phi[16];
#pragma HLS ARRAY_PARTITION variable=Cluster_1_Deposits complete dim=0
 #pragma HLS ARRAY_PARTITION variable=Cluster_1_Eta complete dim=0
  #pragma HLS ARRAY_PARTITION variable=Cluster_1_Phi complete dim=0
#pragma HLS ARRAY_PARTITION variable=cEta complete dim=0
 #pragma HLS ARRAY_PARTITION variable=cPhi complete dim=0
#pragma HLS ARRAY_PARTITION variable=towerETRegions complete dim=0
  
 for(int i=0;i<16;i++)
  {
    Cluster_1_Deposits[i]=0;
    Cluster_1_Phi[i]=0;
    Cluster_1_Eta[i]=0;

  }
  int i=0;
 for(int tPhi = 0; tPhi < 4; tPhi++) {
#pragma HLS UNROLL
    for(int tEta = 0; tEta < 3; tEta++) {
#pragma HLS UNROLL
      Cluster_1_Deposits[i] = towerETRegions[tEta][tPhi];
       Cluster_1_Phi[i]=tPhi;
      Cluster_1_Eta[i]=tEta;
     i++;
    }
  }
for (int i=13;i<16;i++)
{
#pragma HLS UNROLL
 Cluster_1_Deposits[i]=0;
 Cluster_1_Phi[i]=0;
  Cluster_1_Eta[i]=0;
}
//first level of binary comparators
for(int i=0;i<16;i=i+4)
{
#pragma HLS unroll
if(Cluster_1_Deposits[i]<Cluster_1_Deposits[i+1])
{temp=Cluster_1_Deposits[i+1];
Cluster_1_Deposits[i+1]=Cluster_1_Deposits[i];
Cluster_1_Deposits[i]=temp;
temp=Cluster_1_Eta[i];
Cluster_1_Eta[i]=Cluster_1_Eta[i+1];
Cluster_1_Eta[i+1]=temp;
temp=Cluster_1_Phi[i];
Cluster_1_Phi[i]=Cluster_1_Phi[i+1];
Cluster_1_Phi[i+1]=temp;
}

if(Cluster_1_Deposits[i+2]>Cluster_1_Deposits[i+3])
{temp=Cluster_1_Deposits[i+3];
Cluster_1_Deposits[i+3]=Cluster_1_Deposits[i+2];
Cluster_1_Deposits[i+2]=temp;
temp=Cluster_1_Eta[i+2];
Cluster_1_Eta[i+2]=Cluster_1_Eta[i+3];
Cluster_1_Eta[i+3]=temp;
temp=Cluster_1_Phi[i+2];
Cluster_1_Phi[i+2]=Cluster_1_Phi[i+3];
Cluster_1_Phi[i+3]=temp;

}
 }


    // passing control to second level of quaternary comparators
    bitonic_1_4(Cluster_1_Deposits,Cluster_1_Eta,Cluster_1_Phi);
    //copying sorted array back into output variable
for(int i=0;i<5;i++)
{
  cEta[i]=Cluster_1_Eta[i];
  cPhi[i]=Cluster_1_Phi[i];
}
  


}
void TowerPeaks(uint16_t towerET[17][4],  uint16_t TowerPhi[30], uint16_t TowerEta[30])
{
#pragma HLS PIPELINE II=6
#pragma HLS ARRAY_PARTITION variable=towerET complete dim=0

#pragma HLS ARRAY_PARTITION variable=TowerEta complete dim=0
#pragma HLS ARRAY_PARTITION variable=TowerPhi complete dim=0
 
uint16_t regions[3][4];
#pragma HLS ARRAY_PARTITION variable=regions complete dim=0
uint16_t regionEta[5];
#pragma HLS ARRAY_PARTITION variable=regionEta complete dim=0
uint16_t regionPhi[5];
#pragma HLS ARRAY_PARTITION variable=regionPhi complete dim=0
uint16_t Tower_1_Eta[30];
#pragma HLS ARRAY_PARTITION variable=Tower_1_Eta complete dim=0
uint16_t Tower_1_Phi[30];
#pragma HLS ARRAY_PARTITION variable=Tower_1_Phi complete dim=0

#pragma HLS UNROLL
 for (int j=0;j<3;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        regions[j][k]=0;
      }
  }
  for (int i=0;i<5;i++)
  {
    regionEta[i]=0;
    regionPhi[i]=0;
  }
  for(int i=0;i<30;i++)
  {
    Tower_1_Eta[i]=0;
    Tower_1_Phi[i]=0;
  }

int x=0;
for (int i=0;i<15;i=i+3)
{
#pragma HLS UNROLL
 for (int j=0;j<3;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        regions[j][k]=towerET[i+j][k];
      }
  }

getTowerPeaks3x4(regions,regionEta,regionPhi);
Tower_1_Eta[x+0]=regionEta[0]+i;
Tower_1_Eta[x+1]=regionEta[1]+i;
Tower_1_Eta[x+2]=regionEta[2]+i;
Tower_1_Eta[x+3]=regionEta[3]+i;
Tower_1_Eta[x+4]=regionEta[4]+i;
Tower_1_Phi[x+0]=regionPhi[0];
Tower_1_Phi[x+1]=regionPhi[1];
Tower_1_Phi[x+2]=regionPhi[2];
Tower_1_Phi[x+3]=regionPhi[3];
Tower_1_Phi[x+4]=regionPhi[4];
x=x+5;
 }
for (int j=0;j<2;j++)
  {
  #pragma HLS UNROLL
      for (int k=0;k<4;k++)
      {
      #pragma HLS UNROLL
        regions[j][k]=towerET[j+15][k];
      }
  }
  regions[2][0]=0;
  regions[2][1]=0;
  regions[2][2]=0;
  regions[2][3]=0;
  getTowerPeaks3x4(regions,regionEta,regionPhi);
Tower_1_Eta[25+0]=regionEta[0]+15;
Tower_1_Eta[25+1]=regionEta[1]+15;
Tower_1_Eta[25+2]=regionEta[2]+15;
Tower_1_Eta[25+3]=regionEta[3]+15;
Tower_1_Eta[25+4]=regionEta[4]+15;
Tower_1_Phi[25+0]=regionPhi[0];
Tower_1_Phi[25+1]=regionPhi[1];
Tower_1_Phi[25+2]=regionPhi[2];
Tower_1_Phi[25+3]=regionPhi[3];
Tower_1_Phi[25+4]=regionPhi[4];
uint16_t ClusterDeposits2[32];
  uint16_t ClusterEta2[32];
  uint16_t ClusterPhi2[32];
  for(int i=0;i<32;i++)
{
  ClusterDeposits2[i]=0;
  ClusterEta2[i]=0;
  ClusterPhi2[i]=0;
}
#pragma HLS ARRAY_PARTITION variable=ClusterDeposits2 complete dim=0
 #pragma HLS ARRAY_PARTITION variable=ClusterEta2 complete dim=0
  #pragma HLS ARRAY_PARTITION variable=ClusterPhi2 complete dim=0
for(int i=0;i<30;i++)
{
  ClusterDeposits2[i]=towerET[Tower_1_Eta[i]][Tower_1_Phi[i]];
  ClusterEta2[i]=Tower_1_Eta[i];
  ClusterPhi2[i]=Tower_1_Phi[i];
}


int temp=0;
//first level of binary comparators
for(int i=0;i<32;i=i+4)
{
#pragma HLS unroll
if(ClusterDeposits2[i]>ClusterDeposits2[i+1])
{temp=ClusterDeposits2[i+1];
ClusterDeposits2[i+1]=ClusterDeposits2[i];
ClusterDeposits2[i]=temp;
temp=ClusterEta2[i];
ClusterEta2[i]=ClusterEta2[i+1];
ClusterEta2[i+1]=temp;
temp=ClusterPhi2[i];
ClusterPhi2[i]=ClusterPhi2[i+1];
ClusterPhi2[i+1]=temp;
}

if(ClusterDeposits2[i+2]<ClusterDeposits2[i+3])
{temp=ClusterDeposits2[i+3];
ClusterDeposits2[i+3]=ClusterDeposits2[i+2];
ClusterDeposits2[i+2]=temp;
temp=ClusterEta2[i+2];
ClusterEta2[i+2]=ClusterEta2[i+3];
ClusterEta2[i+3]=temp;
temp=ClusterPhi2[i+2];
ClusterPhi2[i+2]=ClusterPhi2[i+3];
ClusterPhi2[i+3]=temp;

}
  }


    // passing control to second level of quaternary comparators
    bitonic4(ClusterDeposits2,ClusterEta2,ClusterPhi2);

    for(int i=0;i<30;i++)
{

  TowerEta[i]=ClusterEta2[i];
  TowerPhi[i]=ClusterPhi2[i];

}
}




