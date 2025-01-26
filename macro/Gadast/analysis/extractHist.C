#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TBranch.h>
#include <iostream>

void extractHist(const char* input_file="resolutionTests/standardDigiNormalLengthSideCuts1mmPlate6cmCo380kBqNoResolutionNoLONU.root", const char* tree_name="er", const char* branch_name="GadastCsIDigi", const char* output_file="loni_hist.root") {
    // Open the input ROOT file
    TFile *file = TFile::Open(input_file);
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Cannot open file " << input_file << std::endl;
        return;
    }

    // Get the TTree from the file
    TTree *tree = (TTree*)file->Get(tree_name);
    if (!tree) {
        std::cerr << "Error: Cannot find tree " << tree_name << std::endl;
        file->Close();
        return;
    }

    // Pointer to hold the histogram
    TH1D *hist = nullptr;

    // Set the branch address to access the histogram
    tree->SetBranchAddress(branch_name, &hist);

    // Loop over entries in the tree to access the histogram (assuming one entry)
    for (int i = 0; i < tree->GetEntries(); ++i) {
        tree->GetEntry(i);

        if (hist) {
            // Open a new ROOT file to save the histogram
            TFile *outputFile = new TFile(output_file, "RECREATE");
            hist->Write();  // Write the histogram to the output file
            outputFile->Close();
            std::cout << "Histogram written to " << output_file << std::endl;

            break;  // Assuming the histogram is stored in only one entry
        } else {
            std::cerr << "Error: Histogram not found in branch " << branch_name << std::endl;
        }
    }

    // Clean up
    file->Close();
}
