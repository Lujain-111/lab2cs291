
// main libraries used 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> 
// Constants for coffee ingredients and prices

#define E_bean 8
#define E_water 30
#define C_beans 8
#define C_water 30
#define C_milk 70
#define M_beans 8
#define M_water 39
#define M_milk 160
#define M_Syrup 30

// constant for low indicators 
#define lowbean 10
#define lowater 50
#define lowmilk 100
#define lowsyrup 20
// prices   

//admin password
#define adminpass 1234
//max threshold
#define MAX_BEANS 100
#define MAX_WATER 500
#define MAX_MILK 300
#define MAX_SYRUP 100


// variables stored (will be used and unpated through the code )
int beans = 100;
int water = 500;
int milk = 300;
int syrup = 100;
double total_amount = 0; 
int espresso_sold = 0;      
int cappuccino_sold = 0;     
int mocha_sold = 0;  
double eprice = 3.5;   
double cprice = 4.5;   
double mprice = 5.5; 


// functions prototype
void order_coffee();
void admin_mode();
void exit_program();
void replenish_ingredients();
void manual_replenish();
void check_ing();
void change_price();
void resets();

// main function
int main() {
    char command; //var to hold user command 
    while (1) { //infinit loop(only excutes while its true)
        
    printf(" choose what you want :\n1) Order a coffee\n2) Admin mode\n3) Exit program\n");// menue options 
    scanf(" %c", &command); 

    switch(command) {//switch cases to call for avaible  functions (options)

        case '1':
            order_coffee(); 
            break;
        case '2':
            admin_mode();
            break;
        case '3':
            exit_program();
            return 0;// terminates the program when chosen 
        default:
            printf("Invalid\n"); //prints when invalid option is typed 
            break;
      }
    }

}


//function when ordering coffee is called 
void order_coffee() {
    //variable to store choice 
    int choice; 
    double price = 0.0;// assigned data type for price(will be updated multiple times through the code )
do {// do loop that will excute once to validate the inputs, then will continue running while true 
    printf(" coffee types:\n");
    if (beans >= E_bean && water >= E_water) { //if statement to  check if there is enough ingredients to make a coffee, if not it wont proceed  to the next step

            printf("1) Espresso - %.2f AED\n", eprice);
    } else {
        printf("1) Espresso - Unavailable due to insufficient ingredients.\n");
    }
    if (beans >= C_beans && water >= C_water && milk >= C_milk) {
        printf("2) Cappuccino - %.2f AED\n", cprice);
    } else {
        printf("2) Cappuccino - Unavailable due to insufficient ingredients.\n");
    }
    if (beans >= M_beans && water >= M_water&& milk >= M_milk && syrup >= M_Syrup) {
        printf("3) Mocha - %.2f AED\n", mprice);
    } else {
        printf("3) Mocha - Unavailable due to insufficient ingredients.\n");
    }

  
    printf("Please choose your coffee (0 to cancel): ");
    scanf("%d", &choice);

// switch case to handle the selection IF THE  USER SELECTED A VALID OPTION, if choice is zero it will return the main loop, continue will trigger the same  loop again to ask for the selection again


    switch(choice) { //switch statement  to handle the selection of coffee type inventory update, while checking for threshold values 

        case 1:
            if (beans >= E_bean && water >= E_water) {
                price = eprice;
                    beans -= E_bean;
                    water -= E_water;
                    espresso_sold++;
                printf("You selected Espresso. Price: %.2f AED.\n", price);
            } else {
                printf("Sorry, Espresso is unavailable.\n");
                continue ;
            }
            break;
        case 2:
            if (beans >= C_beans && water >= C_water && milk >= C_milk) {
                price = cprice;
                    beans -= C_beans;
                    water -= C_water;
                    milk -= C_milk;
                    cappuccino_sold++;
                printf("You selected Cappuccino. Price: %.2f AED.\n", price);
            } else {
                printf(" Cappuccino is unavailable.\n");
                continue;
            }
            break;
        case 3:
            if (beans >= M_beans && water >= M_water&& milk >= M_milk && syrup >= M_Syrup) {
                price = mprice;
                    beans -= M_beans;
                    water -= M_water;
                    milk -= M_milk;
                    syrup -= M_Syrup;
                    mocha_sold++;//updates the sales per  type of coffee(later will be used in admin mode)

                printf("You selected Mocha. Price: %.2f AED.\n", price);
            } else {
                printf("Sorry, Mocha is unavailable.\n");
                continue;
            }
            break;
        case 0:
            printf("Order cancelled.\n");
            return;
        default:
            printf("Invalid selection.\n");
            continue;
    }
  

         double amount_paid = 0.0, coin;

        printf("Insert coins (valid coins: 1 or 0.5 AED):\n");
//while loop to collect the money payed if the amount reached it will break the loop, otherwise it runs until amount is right
        while (amount_paid < price) {
            scanf("%lf", &coin);
            if (coin == 1.0 || coin == 0.5) {
                amount_paid += coin;

                printf("Inserted: %.2f AED. Total paid: %.2f AED.  \n", coin, amount_paid);
            } else {
                printf("Invalid coin. Please insert a valid coin.\n");
            }
        }

        printf("Enjoy your coffee!\n");
         total_amount += price;// updates the total sales amount 
    char order_again;
        printf("\n Do you like to order another coffee? (y/n): ");
        scanf(" %c", &order_again);
    if (order_again != 'y' && order_again != 'Y') {
            printf("Thank you! Have a great day.\n");
            return; 
        }

} while(true);//only runs when the condition is not yet met , in this case it will run until the user chooses to exit the program


}

  

void admin_mode() {
    int pass;//initiaiting variable to store the amdin pass owrd

    while (true) {
        printf("Enter the admin password: ");
        scanf("%d", &pass);

        if (pass == adminpass) {
            int choice;
            int choice2;
            while (true) {
                printf("Admin Menu:\n");
                printf("1) Replenish ingredients\n");
                
                printf("2) Check current inventory\n");
                printf("3)change prices\n");
                printf("4)check total sales/reset\n");
                printf("5) Exit Admin Mode\n");
                scanf("%d", &choice);
                switch (choice) {//multiple switch cases to handle diffrent selections , each selection would call  a different function from the prototype, which will then move to function definition down and excecute 

                   case 1:
                          printf("1) Manual Replenish\n2) random replinish \n");
                          scanf("%d", &choice2);
                          switch (choice2) {
                              case 1:
                                  manual_replenish(); 
                                  break;
                              case 2:
                                  replenish_ingredients(); 
                                  break;
                              default:
                                  printf("Invalid choice. Please try again.\n");
                                  break;
                          }
                          break;
                        
                    case 2:
                        
                        check_ing();
                        break; 
                    case 3:
                        change_price();
                        break;
                    case 4:
                        resets();
                    case 5:
                       printf("Exiting Admin Mode...\n");
                       return;

                    default:
                        printf("Invalid selection, try again.\n");
                }
            }
        } else {
            printf("Wrong password, try again.\n"); 
        }
    }
}
void replenish_ingredients() {
   srand(time(NULL)); //random number generated 
    beans = (rand() % (MAX_BEANS - lowbean + 1)) + lowbean;  // this would generate a value ranging from 0 to max, which will then be added to lowest value to ensure if the number was at zero then the range would be from lower thresh to max 
    water = (rand() % (MAX_WATER - lowater + 1)) + lowater;  
    milk  = (rand() % (MAX_MILK - lowmilk + 1)) + lowmilk;  
    syrup = (rand() % (MAX_SYRUP - lowsyrup + 1)) + lowsyrup; 
  
    printf("Ingredients have been replenished with random values:\n");
    printf("Beans: %d grams (Threshold: %d grams)\n", beans, lowbean);
    printf("Water: %d mil (Threshold: %d mil)\n", water, lowater);
    printf("Milk: %d mil (Threshold: %d mil)\n", milk, lowmilk);
    printf("Syrup: %d mil (Threshold: %d mil)\n", syrup, lowsyrup);
}

void manual_replenish() { //manually inputting the ingrediants values 
    printf("Enter the new values separated by spaces:\n1) New beans\n2) New water\n3) New milk\n4) New syrup\n");
    
    int newbeans, newwater, newmilk, newsyrup;
    
    scanf("%d %d %d %d", &newbeans, &newwater, &newmilk, &newsyrup);
    
    beans = newbeans;
    water = newwater;
    milk = newmilk;
    syrup = newsyrup;
    
    printf("Ingredients have been replenished to the new levels:\n");
    printf("Beans: %d grams\n", beans);
    printf("Water: %d ml\n", water);
    printf("Milk: %d ml\n", milk);
    printf("Syrup: %d mil\n", syrup);
}
void check_ing(){ //void loop to only display current inventory (was updated throughout the code )
printf("the current inventory has Beans: %d grams\n Water: %d mil\n Milk: %d mil\n Syrup: %d mil\n ", beans,water,milk,syrup )
;
}

void change_price() {  //change the price of the drink

    printf("Current Espresso price: %.2f AED\n", eprice);
    printf("Enter new price for Espresso: ");
    scanf("%lf", &eprice);

    
    printf("Current Cappuccino price: %.2f AED\n", cprice);
    printf("Enter new price for Cappuccino: ");
    scanf("%lf", &cprice);
    
    printf("Current Mocha price: %.2f AED\n", mprice);
    printf("Enter new price for Mocha: ");
    scanf("%lf", &mprice);
    
    printf("Prices updated successfully.\n");

}

void resets(){// loop to reset the session if needed, while checking for current sales amount
 printf("Total sales for this session: %.2f AED\n", total_amount);
    printf("Espresso sold: %d\n", espresso_sold);
    printf("Cappuccino sold: %d\n", cappuccino_sold);
    printf("Mocha sold: %d\n", mocha_sold);

  
    char reset_choice;
    printf("Do you want to reset total sales and quantities sold to zero? (y/n): ");
    scanf(" %c", &reset_choice);

   
    if (reset_choice == 'y' || reset_choice == 'Y') { // condition to reset with checking if choice was in capital or lower 
        total_amount = 0;           
        espresso_sold = 0;           
        cappuccino_sold = 0;         
        mocha_sold = 0;             
        printf("Total sales and quantities sold have been reset to 0.\n");
    
}
}
void exit_program() {
    printf(" bye!\n");
    
}
