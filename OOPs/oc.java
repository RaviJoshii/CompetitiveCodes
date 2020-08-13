public class oc {
    public class ic1{
        int d11;
        // static int d22;

        void fun(){

        }

        // static void sfun(){

        // }
    }

    static public class ic2{
        int d1;
        static int d2;

        void fun(){

        }

        static void sfun(){

        }
    }

    int d1;
    static int d2;

    void fun(){
        d2 = 100; // fine
        sfun();
        ic2 o2 = new ic2();

        

        d1 = 10; // not allowed
        fun(); // not allowed
        ic1 o1 = new ic1(); 
    }

    static void sfun(){
        d2 = 100; // fine
        sfun();
        ic2 o2 = new ic2();

        oc o = new oc();

        o.d1 = 10; // not allowed
        o.fun(); // not allowed
        ic1 o1 = o.new ic1(); 
    }

    static void main(String[] args){
        // d2 = 100; // fine
        // sfun();
        // ic2 o2 = new ic2();

        // oc o = new oc();

        // o.d1 = 10; // not allowed
        // o.fun(); // not allowed
        // ic1 o1 = o.new ic1(); // not allowed
        final int i ;

        i = 10;

        // i = 20;

        System.out.println(i);
        
    }
}