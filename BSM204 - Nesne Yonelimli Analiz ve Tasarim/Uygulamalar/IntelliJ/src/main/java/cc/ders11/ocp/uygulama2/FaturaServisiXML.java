package cc.ders11.ocp.uygulama2;


public class FaturaServisiXML implements IFaturaServisi {

    public String faturaOlustur(Fatura fatura){

        String faturaXML="<XML>"+fatura.toString();
        return faturaXML;

    }

}
