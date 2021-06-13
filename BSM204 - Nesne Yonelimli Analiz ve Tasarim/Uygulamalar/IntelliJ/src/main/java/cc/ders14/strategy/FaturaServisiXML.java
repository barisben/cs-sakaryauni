package cc.ders14.strategy;

public class FaturaServisiXML implements IFaturaServisi {

    public String faturaOlustur(Fatura fatura){

        String faturaXML="<XML>"+fatura.toString();
        return faturaXML;
    }
}