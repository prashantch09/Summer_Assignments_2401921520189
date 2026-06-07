interface LibraryUser {

    abstract void registerAccount();
    abstract void requestBook();
}

class KidUser implements LibraryUser {

    int age;
    String bookType;

    @Override
    public void registerAccount(){

        if(age < 12){
            System.out.println("You have successfully registered under a Kids account");
        }
        else{
            System.out.println("Sorry, age must be less than 12 to register as a kid");
        }
    }

    @Override
    public void requestBook(){

        if(bookType.equalsIgnoreCase("kids")){
            System.out.println("Book Issued successfully, please return the book within 10 days");
        }
        else{
            System.out.println("Oops, you are allowed to take only kids books");
        }
    }
}

class AdultUser implements LibraryUser {

    int age;
    String bookType;

    @Override
    public void registerAccount(){

        if(age >= 12){
            System.out.println("You have successfully registered under an Adult Account");
        }
        else{
            System.out.println("Sorry, Age must be greater than 12 to register as an Adult");
        }
    }

    @Override
    public void requestBook(){

        if(bookType.equalsIgnoreCase("fiction")){
            System.out.println("Book Issued successfully, please return the book within 7 days");
        }
        else{
            System.out.println("Oops, you are allowed to take only adult Fiction books");
        }
    }
}

public class LibraryInterfaceDemo {
    public static void main(String[] args) {

        //Test case 1:
        KidUser tom = new KidUser();
        tom.age = 10;
        tom.registerAccount();

        tom.age = 18;
        tom.registerAccount();

        tom.bookType = "kids";
        tom.requestBook();

        tom.bookType = "fiction";
        tom.requestBook();

        //Test case 2:
        AdultUser bob = new AdultUser();
        bob.age = 5;
        bob.registerAccount();

        bob.age = 23;
        bob.registerAccount();

        bob.bookType = "kids";
        bob.requestBook();

        bob.bookType = "fiction";
        bob.requestBook();
    }   
}