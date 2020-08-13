public class client{
    public static void main(String[] args){
        // parent o1 = new parent();

        // o1.fun();
        // o1.fun1();
        // o1.fun2(); - compile time

        // System.out.println(o1.d);
        // System.out.println(o1.d1);
        // System.out.println(o1.d2); - compile time

        // parent o2 = new child();

        // o2.fun();
        // o2.fun1();
        // o2.fun2(); - compile time

        // System.out.println(o2.d);
        // System.out.println(o2.d1);
        // System.out.println(o2.d2); - compile time

        // child o3 = new parent();

        // o3.fun();
        // o3.fun1();
        // o3.fun2(); // - compile time

        // System.out.println(o3.d);
        // System.out.println(o3.d1);
        // System.out.println(o3.d2); // - compile time


        child o4 = new child();
        o4.fun();
        o4.fun1();
        o4.fun2(); 

        System.out.println(o4.d);
        System.out.println(o4.d1);
        System.out.println(o4.d2); 

    }
}