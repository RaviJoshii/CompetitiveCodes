public class account {
    int amount = 10;
    int ano;
    static double roi = .04;
    static int count;
    
    account()
    {
        count++;
        ano = count;
    }

    account(int amount)
    {
        this.amount += amount;
    }

    public static void main(String[] args){
    }
}