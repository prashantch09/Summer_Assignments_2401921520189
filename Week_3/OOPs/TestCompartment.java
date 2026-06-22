import java.util.Random;

abstract class Compartment{

    public abstract String notice();
}

class FirstClass extends Compartment{

    @Override
    public String notice(){
        return "This is First Class Compartment";
    }
}

class Ladies extends Compartment{

    @Override
    public String notice(){
        return "This is Ladies Compartment";
    }
}

class General extends Compartment{

    @Override
    public String notice(){
        return "This is General compartment";
    }
}

class Luggage extends Compartment{

    @Override
    public String notice(){
        return "This is Luggage Compartment";
    }
}

public class TestCompartment{
    public static void main(String[] args) {

        Compartment[] Rail = new Compartment[10];
        Random rand = new Random();

        for(int i=0; i<10; i++){
            int n = rand.nextInt((4 - 1) + 1) + 1;
            switch (n){
                case 1 :
                    Rail[i] = new FirstClass();
                    break;
                case 2 :
                    Rail[i] = new Ladies();
                    break;
                case 3 :
                    Rail[i] = new General();
                    break;
                case 4 :
                    Rail[i] = new Luggage();
                    break;
            }
        }

        //checking the polymorphic behaviour
        for(int j=0; j<10; j++){
            System.out.println(Rail[j].notice());
        }
    }
}