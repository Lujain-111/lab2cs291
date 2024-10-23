

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> 

#define E_bean 8
#define E_water 30
#define C_beans 8
#define C_water 30
#define C_milk 70
#define M_beans 8
#define M_water 39
#define M_milk 160
#define M_Syrup 30


#define lowbean 10
#define lowater 50
#define lowmilk 100
#define lowsyrup 20

#define eprice 3.5
#define cprice 4.5
#define mprice 5.5

#define adminpass 1234

#define MAX_BEANS 100
#define MAX_WATER 500
#define MAX_MILK 300
#define MAX_SYRUP 100


int beans = 100;
int water = 500;
int milk = 300;
int syrup = 100;
double total_amount = 0; 
int espresso_sold = 0;      
int cappuccino_sold = 0;     
int mocha_sold = 0;   


void order_coffee();
void admin_mode();
void exit_program();
void replenish_ingredients();
void manual_replenish();
void check_ing();
void change_price();
void resets();


int main() {
    char command;
    while (1) { 
        
    printf(" choose what you want :\n1) Order a coffee\n2) Admin mode\n3) Exit program\n");
    scanf(" %c", &command); 

    switch(command) {
        case '1':
            order_coffee();
            break;
        case '2':
            admin_mode();
            break;
        case '3':
            exit_program();
            return 0;
        default:
            printf("Invalid\n");
            break;
      }
    }

}



void order_coffee() {
    int choice;
    double price = 0.0;
do {
    printf(" coffee types:\n");
    if (beans >= E_bean && water >= E_water) {
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


    switch(choice) {
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
                    mocha_sold++;
                printf("You selected Mocha. Price: %.2f AED.\n", price);
            } else {
                printf("Sorry, Mocha is unavailable.\n");
                continue;;
            }
            break;
        case 0:
            printf("Order cancelled.\n");
            return;
        default:
            printf("Invalid selection.\n");
            continue;
    }
  

         double amount_paid = 0.0, coin,remainder;

        printf("Insert coins (valid coins: 1 or 0.5 AED):\n");

        while (amount_paid < price) {
            scanf("%lf", &coin);
            if (coin == 1.0 || coin == 0.5) {
                amount_paid += coin;
                remainder = amount_paid-price;

                printf("Inserted: %.2f AED. Total paid: %.2f AED.  \n", coin, amount_paid);
            } else {
                printf("Invalid coin. Please insert a valid coin.\n");
            }
        }

        printf("Change:%.2f \t\n Enjoy your coffee!\n",remainder);
         total_amount += price;
    char order_again;
        printf("\n Do you like to order another coffee? (y/n): ");
        scanf(" %c", &order_again);
    if (order_again != 'y' && order_again != 'Y') {
            printf("Thank you! Have a great day.\n");
            return; 
        }

} while(true);

}

  

void admin_mode() {
    int pass;
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
                switch (choice) {
                   case 1:
                          printf("1) Manual Replenish\n2) Automatic MAXOUT\n");
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
                        return; 
                        case 3:
                        change_price();

                        break;
                        case 4:
                        resets();
                        case 5:
                       printf("Exiting Admin Mode...\n");
                        break;

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
    srand(time(NULL));
    beans = (rand() % (MAX_BEANS - lowbean + 1)) + lowbean;  
    water = (rand() % (MAX_WATER - lowater + 1)) + lowater;  
    milk  = (rand() % (MAX_MILK - lowmilk + 1)) + lowmilk;  
    syrup = (rand() % (MAX_SYRUP - lowsyrup + 1)) + lowsyrup; 

    printf("Ingredients have been replenished with random values:\n");
    printf("Beans: %d grams (Threshold: %d grams)\n", beans, lowbean);
    printf("Water: %d milliliters (Threshold: %d milliliters)\n", water, lowater);
    printf("Milk: %d milliliters (Threshold: %d milliliters)\n", milk, lowmilk);
    printf("Syrup: %d milliliters (Threshold: %d milliliters)\n", syrup, lowsyrup);
}

void manual_replenish() {
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
void check_ing(){
printf("the current inventory has Beans: %d grams\n Water: %d milliliters\n Milk: %d milliliters\n Syrup: %d milliliters\n ", beans,water,milk,syrup )
;
}

void change_price() {
    int choice;
    double new_price;

    printf("Which coffee price would you like to change?\n");
    printf("1) Espresso\n");
    printf("2) Cappuccino\n");
    printf("3) Mocha\n");
    printf("0) Cancel\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new price for Espresso: ");
            scanf("%lf", &new_price);
             new_price=eprice;  
            printf("Espresso price updated to %.2f AED.\n", eprice);
            break;
        case 2:
            printf("Enter new price for Cappuccino: ");
            scanf("%lf", &new_price);
             new_price=cprice ;  
            printf("Cappuccino price updated to %.2f AED.\n", cprice);
            break;
        case 3:
            printf("Enter new price for Mocha: ");
            scanf("%lf", &new_price);
            new_price= mprice ;  
            printf("Mocha price updated to %.2f AED.\n", mprice);
            break;
        case 0:
            printf("Price change cancelled.\n");
            break;
        default:
            printf("Invalid selection, please try again.\n");
            break;
    }


}

void resets(){
 printf("Total sales for this session: %.2f AED\n", total_amount);
    printf("Espresso sold: %d\n", espresso_sold);
    printf("Cappuccino sold: %d\n", cappuccino_sold);
    printf("Mocha sold: %d\n", mocha_sold);

  
    char reset_choice;
    printf("Do you want to reset total sales and quantities sold to zero? (y/n): ");
    scanf(" %c", &reset_choice);

   
    if (reset_choice == 'y' || reset_choice == 'Y') {
        total_amount = 0;           
        espresso_sold = 0;           
        cappuccino_sold = 0;         
        mocha_sold = 0;             
        printf("Total sales and quantities sold have been reset to 0.\n");
    
}
}
void exit_program() {
    printf(" Goodbye!\n");
    
}
//remove the milliletrs ,,,rand remove teh refund option 