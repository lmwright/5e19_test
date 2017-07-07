#include <iostream>
#include "TH1D.h"
#include "TFile.h"
#include "TBranch.h"
#include "TDirectory.h"
#include "TTree.h"

int main()
{
  float x_min = 0;
  float x_max = 258;
  float y_min = -117;
  float y_max = 117;
  float z_min = 0;
  float z_max = 1036;

  TFile* example_file = new TFile("ana_hist_example.root");

  example_file->cd("analysistree");
  TTree* anatree = (TTree*)example_file->Get("anatree");
  float x_pos[100];
  float y_pos[100];
  float z_pos[100];
  anatree->SetBranchAddress("nuvtxx_truth", &x_pos);
  anatree->SetBranchAddress("nuvtxy_truth", &y_pos);
  anatree->SetBranchAddress("nuvtxz_truth", &z_pos);

  int nentries = anatree->GetEntries();
  int count = 0;

  for (int i=0;i<nentries; i++)
  {
    anatree->GetEntry(i);
    if (x_pos[i]>=x_min && x_pos[i]<=x_max && y_pos[i]>=y_min && y_pos[i]<=y_max && z_pos[i]>=z_min && z_pos[i]<=z_max)
      count++;
  }

  std::cout << count << std::endl;
  return 0;
}
