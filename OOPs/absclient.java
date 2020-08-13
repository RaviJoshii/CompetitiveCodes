public class absclient {
    static class a {
        a(){
            System.out.println("a");
        }
    }
    static class b extends a {
        b(){
            System.out.println("b");
            a o = new a();
        }
    }

    static class c extends b{
        c(){
            System.out.println("c");
            b o = new b();
        }
    }

    static class d extends c{
        d(){
            System.out.println("d");
            c o = new c();
        }
    }
    // static abstract class a{
    //     int p1;
    //     // a(int p1){
    //     //     this.p1 = p1;
    //     // }
    //     abstract void fun();
    // } 

    // static abstract class b extends a {
    //     int p2;
    //     // b(int p1, int p2){
    //     //     super(p1);
    //     //     this.p2 = p2;
    //     // }
    // } 

    // static class c extends b{
    //     c(int p1, int p2, int p3){
    //         // super(p1, p2);
    //         this.p3 = p3;
    //     }
    //     int p3;
    //     void fun(){

    //     }
    // } 


    public static void main(String[] args){
        // abs o1 = new cabs();
        // cabs o2 = new cabs();
        d obj = new d();
    }
}