#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// show food category items
void showFood(){
    printf("\n--- Food Category ---\n");
    printf("11. Marshmello - RM 8.99\n");
    printf("12. Maggi Kari - RM 7.00\n");
    printf("13. Sour Candy - RM 6.50\n");
    printf("20. Coffee Beans 1kg - RM 39.90\n");
}

// show electronics category items
void showElectronics(){
    printf("\n--- Electronics Category ---\n");
    printf("3. Xbox Controller - RM 185.00\n");
    printf("4. MSI Monitor 144Hz - RM 369.90\n");
    printf("6. Razer Keyboard - RM 138.88\n");
    printf("8. HyperX Headphones - RM 241.91\n");
    printf("9. iPhone 13 - RM 1,809.00\n");
    printf("14. Gaming Mouse - RM 59.90\n");
    printf("15. Mechanical Keyboard - RM 249.00\n");
    printf("16. Bluetooth Speaker - RM 120.00\n");
}

// show plants category items
void showPlants(){
    printf("\n--- Plants Category ---\n");
    printf("5. Jasmine Seeds - RM 5.99\n");
    printf("17. Cactus - RM 12.50\n");
    printf("18. Bonsai Tree - RM 99.00\n");
    printf("19. Orchid - RM 45.00\n");
}



int main(){
    // cart storage variables
    int qty[100],i=0,j;
    float price[100],grandTotal=0;
    char prodName[100][50];
    int item;
    char opt,search[20];

    // title and promotions
    printf("\t\t\t\t\t\tSHOPEE\t\t\t\t\t\t");
    printf("\n\t\t\t\t\tSUPER PROMO THIS WEEK!!!\t\t\t\t\t\t");
    printf("\n\t\t\t\t\tOnly On 30.9.25 - 9.10.25\t\t\t\t\t\t");

    // suggested items display
    printf("\nSuggested Items.\n");
    printf("1. Munchy Chocolate\t2. Math Textbook\t3. Xbox Controller\t4. MSI Monitor 144Hz\t5. Jasmine Seeds\n");
    printf("Ratings\t112\t\tRatings\t50\t\tRatings\t112\t\tRatings\t454\t\tRatings\t1.2k\n");
    printf("RM 9.90\t\t\tRM 29.00\t\tRM 185.00\t\tRM 369.90\t\tRM 5.99\t\t\t");
    printf("\n\n6. Razer Keyboard\t7. Pringles 12x Cans\t8. HyperX Headphones\t9. iPhone 13\t\t10. Deluxe Pillow\n");
    printf("Ratings\t191\t\tRatings\t4.3k\t\tRatings\t72\t\tRatings\t569\t\tRatings\t3.2k\n");
    printf("RM 138.88\t\tRM 16.90\t\tRM 241.91\t\tRM 1,809.00\t\tRM 29.80\t\t\t\n\n");
    printf("11. Marshmello\t\t12. Maggi Kari\t\t13. Sour Candy\t\t14. Gaming Mouse\t15. Mechanical Keyboard\n");
    printf("Ratings\t87\t\tRatings\t1.1k\t\tRatings\t640\t\tRatings\t800\t\tRatings\t240\n");
    printf("RM 8.99\t\t\tRM 7.00\t\t\tRM 6.50\t\t\tRM 59.90\t\tRM 249.00\n");
    printf("\n16. Bluetooth Speaker\t17. Cactus\t\t18. Bonsai Tree\t\t19. Orchid\t\t20. Coffee Beans 1kg\n");
    printf("Ratings\t410\t\tRatings\t220\t\tRatings\t90\t\tRatings\t150\t\tRatings\t560\n");
    printf("RM 120.00\t\tRM 12.50\t\tRM 99.00\t\tRM 45.00\t\tRM 39.90\n\n");

    // main loop for user interaction
    while(1){
        printf("\nEnter item number to add to cart, 'S' to stop, 'O' to search, or 'C' to open cart: ");
        if(scanf(" %c",&opt)!=1)break;

        // stop program
        if(opt=='S'||opt=='s'){
            printf("Stopping item selection...\n");
            break;
        } 

        // cart menu
        if(opt=='C'||opt=='c'){ 
            int cartChoice;
            printf("\n--- Your Cart Menu ---\n");
            printf("1. View Cart\n");
            printf("2. Remove Item from Cart\n");
            printf("3. Checkout\n");
            printf("Choose: ");
            scanf("%d",&cartChoice);

            // view cart
            if(cartChoice==1){
                grandTotal=0;
                printf("\n--- Your Cart ---\n");
                for(j=0;j<i;j++){
                    float subtotal=price[j]*qty[j];
                    printf("%d x %s | RM %.2f each = RM %.2f\n",qty[j],prodName[j],price[j],subtotal);
                    grandTotal+=subtotal;
                }
                if(i==0){ //i=0 because nothing added, if something is added it will i++
                    printf("Your cart is empty!\n");
                }else{ //if i not 0
                    printf("Grand Total: RM %.2f\n",grandTotal);
                }
            }

            // remove item
            else if(cartChoice==2){
                if(i==0){
                    printf("Your cart is empty, nothing to remove!\n");
                }else{
                    int removeIndex;
                    printf("Enter item number (1-%d) to remove: ",i);
                    scanf("%d",&removeIndex);
                    if(removeIndex<1||removeIndex>i){ //if didnt add anything into cart i will be 0. so it will show error when u want to remove items.
                        printf("Invalid item number!\n");
                    }else{
                    	int k;
                        removeIndex--; //item removed from cart
                        printf("Removed %s from cart.\n",prodName[removeIndex]);
                        for( k=removeIndex;k<i-1;k++){
                            strcpy(prodName[k],prodName[k+1]); //use strcpy bc string do like x= prodName[1]
                            price[k]=price[k+1];
                            qty[k]=qty[k+1];
                        }
                        i--;
                    }
                }
            }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
            // checkout
            else if(cartChoice==3){
                if(i==0){
                    printf("Your cart is empty, cannot checkout!\n");
                }else{
                    grandTotal=0;
                    for(j=0;j<i;j++){
                        float subtotal=price[j]*qty[j];
                        grandTotal+=subtotal;
                    }

                    // ask for delivery address
                    char address[200];
                    printf("\nEnter your delivery address: ");
                    getchar();
                    fgets(address,sizeof(address),stdin);
                    address[strcspn(address,"\n")]='\0';

                    // choose shipping method
                    int shippingChoice;
                    float shipping=0.0;
                    printf("\nChoose shipping method:\n");
                    printf("1. Self-pickup (RM 5.00)\n");
                    printf("2. Standard delivery (RM 10.00)\n");
                    printf("3. Express delivery (RM 20.00)\n");
                    printf("Enter choice: ");
                    scanf("%d",&shippingChoice);
                    if(shippingChoice==1)shipping=5.0;
                    else if(shippingChoice==2)shipping=10.0;
                    else if(shippingChoice==3)shipping=20.0;
                    else{
                        printf("Invalid choice, default standard delivery applied.\n");
                        shipping=10.0;
                    }

                    // tax calculation
                    float tax=grandTotal*0.06;
                    float finalTotal=grandTotal+tax+shipping;

                    // print receipt
                    printf("\n--- Checkout ---\n");
                    printf("Delivery Address: %s\n",address);
                    printf("Items: %d\n",i);
                    printf("Subtotal: RM %.2f\n",grandTotal);
                    printf("Tax (6%%): RM %.2f\n",tax);
                    printf("Shipping: RM %.2f\n",shipping);
                    printf("Total Amount: RM %.2f\n",finalTotal);
                    printf("Thank you for shopping!\n");
                    i=0;
                }
            }

            // invalid cart choice
            else{
                printf("Invalid choice!\n");
            }
            continue;
        }

        // search category
        if(opt=='O'||opt=='o'){
            printf("Search mode enabled. Enter keyword (food/electronics/plants): ");
            scanf("%s",search);
            if(strcmp(search,"food")==0||strcmp(search,"FOOD")==0){
                showFood();
            }else if(strcmp(search,"electronics")==0||strcmp(search,"ELECTRONICS")==0){
                showElectronics();
            }else if(strcmp(search,"plants")==0||strcmp(search,"PLANTS")==0){
                showPlants();
            }else{
                printf("Category not found.\n");
            }
            continue;
        }

        // handle item number input (support multi-digit)
        ungetc(opt,stdin);
        if(scanf("%d",&item)!=1){
            printf("Invalid input. Try again.\n");
            continue;
        }

        // add selected item to cart
        if(item>=1&&item<=20){
            switch(item){
                case 1:price[i]=9.90;strcpy(prodName[i],"Munchy Chocolate");break;
                case 2:price[i]=29.00;strcpy(prodName[i],"Math Textbook");break;
                case 3:price[i]=185.00;strcpy(prodName[i],"Xbox Controller");break;
                case 4:price[i]=369.90;strcpy(prodName[i],"MSI Monitor 144Hz");break;
                case 5:price[i]=5.99;strcpy(prodName[i],"Jasmine Seeds");break;
                case 6:price[i]=138.88;strcpy(prodName[i],"Razer Keyboard");break;
                case 7:price[i]=16.90;strcpy(prodName[i],"Pringles 12x Cans");break;
                case 8:price[i]=241.91;strcpy(prodName[i],"HyperX Headphones");break;
                case 9:price[i]=1809.00;strcpy(prodName[i],"iPhone 13");break;
                case 10:price[i]=29.80;strcpy(prodName[i],"Deluxe Pillow");break;
                case 11:price[i]=8.99;strcpy(prodName[i],"Marshmello");break;
                case 12:price[i]=7.00;strcpy(prodName[i],"Maggi Kari");break;
                case 13:price[i]=6.50;strcpy(prodName[i],"Sour Candy");break;
                case 14:price[i]=59.90;strcpy(prodName[i],"Gaming Mouse");break;
                case 15:price[i]=249.00;strcpy(prodName[i],"Mechanical Keyboard");break;
                case 16:price[i]=120.00;strcpy(prodName[i],"Bluetooth Speaker");break;
                case 17:price[i]=12.50;strcpy(prodName[i],"Cactus");break;
                case 18:price[i]=99.00;strcpy(prodName[i],"Bonsai Tree");break;
                case 19:price[i]=45.00;strcpy(prodName[i],"Orchid");break;
                case 20:price[i]=39.90;strcpy(prodName[i],"Coffee Beans 1kg");break;
            }
            printf("Enter quantity for %s: ",prodName[i]);
            scanf("%d",&qty[i]);
            printf("%d x %s added to cart!\n",qty[i],prodName[i]);
            i++;
        }else{
            printf("Invalid input. Try again.\n");
        }
    }
    return 0;
}

