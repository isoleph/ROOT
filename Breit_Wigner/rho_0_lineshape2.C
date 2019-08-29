void rho_0_lineshape2()
{
   TCanvas *c1 = new TCanvas("c1", "c1",339,236,700,502);
   c1->Range(437.5,-0.000464405,1062.5,0.005071834);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetGridx();
   c1->SetGridy();
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TF1 *func1 = new TF1("func","#rho^{0} lineshape",500,1000, TF1::EAddToList::kDefault);
   func1->SetNpx(1000);
   func1->SetFillColor(19);
   func1->SetFillStyle(0);
   func1->SetLineColor(2);
   func1->SetLineWidth(2);
   func1->GetXaxis()->SetTitle("E_{0} (MeV)");
   func1->GetXaxis()->SetLabelFont(42);
   func1->GetXaxis()->SetLabelSize(0.035);
   func1->GetXaxis()->SetTitleSize(0.035);
   func1->GetXaxis()->SetTitleOffset(1);
   func1->GetXaxis()->SetTitleFont(42);
   func1->GetYaxis()->SetTitle("#rho(E)");
   func1->GetYaxis()->SetLabelFont(42);
   func1->GetYaxis()->SetLabelSize(0.035);
   func1->GetYaxis()->SetTitleSize(0.035);
   func1->GetYaxis()->SetTitleFont(42);
   func1->SetParameter(0,147.8);
   func1->SetParError(0,0);
   func1->SetParLimits(0,0,0);
   func1->SetParameter(1,775.26);
   func1->SetParError(1,0);
   func1->SetParLimits(1,0,0);
   func1->Draw("");
   
   TLegend *leg = new TLegend(0.1275072,0.7136842,0.4255014,0.8715789,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("func","Neutral Rho Meson","lpf");
   entry->SetFillColor(19);
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.3911461,0.9343684,0.6088539,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("#rho^{0} lineshape");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
