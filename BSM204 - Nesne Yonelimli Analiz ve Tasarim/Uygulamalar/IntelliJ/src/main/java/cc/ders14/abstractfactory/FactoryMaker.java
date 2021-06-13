package cc.ders14.abstractfactory;

class FactoryMaker{
    private static AbstractGUIFactory pf=null;
    static AbstractGUIFactory getFactory(String choice){
        if(choice.equals("u")){
            pf=new UbuntuFactory();
        }else if(choice.equals("a")){
            pf=new AndroidFactory();
        } return pf;
    }
}
