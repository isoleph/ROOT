#include <iostream>
#include <TMath.h>
#include <TH1F.h>
#include <TCanvas.h>


// values in eV
double Br = 7.725;      // window
double M = 134.987;     // mass

int pion_0_lineshape() {

    // create canvas
    TCanvas* c1 = new TCanvas("c1", "c1", 350, 250, 700, 500); {
        c1->SetGridx();
        c1->SetGridy();
        c1->Draw();
    }

    TF1* func = new TF1("func", 
        "ROOT::Math::breitwigner_pdf(x, [0], [1])", 134.954, 135.054); {
        
        // set parameters
        func->SetParameter(0, Br); func->SetParName(0, "Decay Width");
        func->SetParameter(1, M); func->SetParName(1, "Mass");

        // label axes
        func->SetTitle("#pi^{0} lineshape");
        func->GetXaxis()->SetTitle("E_{0}");
        func->GetYaxis()->SetTitle("#rho (E)");
    }

    // create legend
    TLegend* leg = new TLegend(); {
        leg->AddEntry(func, "Neutral Pi Meson");
    }

    // draw lineshape
    func->Draw();
    leg->Draw("SAME");
    return 0;
}

