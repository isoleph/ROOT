#include <iostream>
#include <TMath.h>
#include <TH1F.h>
#include <TCanvas.h>


// values in eV
double M = 775.26;    // mass
double Br = 147.8;    // decay width

int rho_0_lineshape() {

    // create canvas
    TCanvas* c1 = new TCanvas("c1", "c1", 350, 250, 700, 500); {
        c1->SetGridx(); 
        c1->SetGridy();
        c1->Draw();
    }

    // create BW lineshape
    TF1* func = new TF1( "func", 
        "ROOT::Math::breitwigner_pdf(x, [0], [1])", 500, 1000); {

            // set parameters
            func->SetParameter(0, Br); func->SetParName(0, "Width");
            func->SetParameter(1, M); func->SetParName(1, "Mass");

            // label axes
            func->SetTitle("#rho^{0} lineshape");
            func->GetXaxis()->SetTitle("E_{0} (eV)");
            func->GetYaxis()->SetTitle("#rho (E)");
    }

    // create legend
    TLegend* leg = new TLegend(); {
        leg->AddEntry(func, "Neutral Rho Meson");
    }

    // draw lineshape
    func->Draw();
    leg->Draw("SAME");
    c1->cd();
    return 0;
}

