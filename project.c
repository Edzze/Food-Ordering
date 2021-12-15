#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct restaurants {
	char restaurant[100];
	char menu1[20];
	char menu2[20];
	char menu3[20];
	char menu4[25];
	int price1, price2, price3, price4;
};

struct restaurants m[3];
void cart();
void find_by_restaurant();
void find_by_menu();
void food_order(int food);

// Function to initialize the restaurant and foods

void restaurant_initialize();
void restaurants(int res_choice);
int i, j = 0, count = 0;
int choice;
int total = 0, food_choice, n;
int res_choice, search_choice, confirm;
int ch, food, id;


// Food Ordering System
int main()
{
	while (1) {
         char name[10];
		printf("Welcome to Food Ordering System\n");
        printf("Enter your name: ");
        fgets(name, 10, stdin);

        printf("Hello %s \n", name);
		printf("There are two ways to search for your order ");
        printf("\n1) Search By Restaurant \n2) Search by Food \n3) Exit");
        printf("\n\nPlease Enter your choice: \t");
        scanf("%d", &search_choice);

        switch (search_choice) {
				case 1: {
					find_by_restaurant();
					break;
				}
				case 2: {
					find_by_menu();
					break;
				}
				case 3: {
					exit(0);
				}
				default: {
					printf("Please Enter the available choice");
					break;
				}
				}
				break;
			}
}

// Initializes all the restaurants, its menus, and its price
void restaurant_initialize()
{
	// Initializing the structure Japan foods
	strcpy(m[1].restaurant, "Japan foods");
	strcpy(m[1].menu1, "Sushi set");
	strcpy(m[1].menu2, "Ramen set");
	strcpy(m[1].menu3, "Takoyaki");
	m[1].price1 = 200;
	m[1].price2 = 260;
	m[1].price3 = 120;

	// Initializing the structure Thai's
	strcpy(m[2].restaurant, "Thai's");
	strcpy(m[2].menu1, "Pad-Thai");
	strcpy(m[2].menu2, "Tom-Yum-Kung");
	strcpy(m[2].menu3, "Thai-Green-Curry");
	m[2].price1 = 60;
	m[2].price2 = 100;
	m[2].price3 = 80;

	// Initializing the structure Chinese place
	strcpy(m[3].restaurant, "Chinese place");
	strcpy(m[3].menu1, "Spring Rolls");
	strcpy(m[3].menu2, "Dim Sums");
	strcpy(m[3].menu3, "Quick Noodles");
	m[3].price1 = 80;
	m[3].price2 = 120;
	m[3].price3 = 100;
}

// Function choose a restaurant
void find_by_restaurant()
{
	restaurant_initialize();
	printf("\n\nPlease Choose a restaurant \n1) %s\n2) %s\n3) %s",
         m[1].restaurant, m[2].restaurant, m[3].restaurant);
	printf("\n4) Exit");
	printf("\n\n Please select a restaurant: \t");
	scanf("%d", &res_choice);

	if (res_choice > 4) {
		printf("Please Enter a valid choice");
		find_by_restaurant();
	}
	else if (res_choice == 4)
		main();
	else
		restaurants(res_choice);
}

// Function to implement the restaurant
void restaurants(int res_choice)
{
	total = 0;
	while (1) {

		// Displays the list of food
		printf("\n\nList of foods available ");
		printf("in %s\n\n1) %s\tBaht: %d\n2) ",
            m[res_choice].restaurant, m[res_choice].menu1, m[res_choice].price1);

		printf("%s\tBaht: %d\n3) %s\tBaht: %d\n4) ",
			m[res_choice].menu2, m[res_choice].price2, m[res_choice].menu3, m[res_choice].price3);

		printf("Cart\n5) Exit\n\nPlease Enter Your Choice\t ");
		scanf("%d", &food_choice);

		// Get the input for amount of food and calculates the total amount
		if (food_choice == 1) {
			printf("Please Enter the amount of %s\t ", m[res_choice].menu1);
			scanf("%d", &n);
			total = total + (n * m[res_choice].price1);
		}
		else if (food_choice == 2) {
			printf("Please Enter the amount of %s\t", m[res_choice].menu2);
			scanf("%d", &n);
			total = total + (n * m[res_choice].price2);
		}
		else if (food_choice == 3) {
			printf("Please Enter the amount of %s\t", m[res_choice].menu3);
			scanf("%d", &n);
			total = total + (n * m[res_choice].price3);
		}
		else if (food_choice == 4) {
			cart();
		}
		else if (food_choice == 5) {
			find_by_restaurant();
		}
		else {
			printf("Please Enter a Valid Choice\n");

		}
	}
}

void find_by_menu()
{
	total = 0;

	// Initialize all the restaurant and their food
	restaurant_initialize();
	while (1) {
        printf("\n\nPlease choose the menu");
        printf("\n1) %s\t%d \n2) %s\t%d \n3) %s\t%d",
               m[1].menu1, m[1].price1, m[1].menu2, m[1].price2, m[1].menu3, m[1].price3);
        printf("\n4) %s\t%d \n5) %s\t%d \n6) %s\t%d",
               m[2].menu1, m[2].price1, m[2].menu2, m[2].price2, m[2].menu3, m[2].price3);
        printf("\n7) %s\t%d \n8) %s\t%d \n9) %s\t%d",
               m[3].menu1, m[3].price1, m[3].menu2, m[3].price2, m[3].menu3, m[3].price3);
        printf("\n10) Cart \n11) Exit");

		printf("\nPlease Enter Your Choice\t");
		scanf("%d", &food);
		if (food > 10) {
			printf("Please Enter the valid choice\n");
			find_by_menu();
		}
		// Moves to the cart
		else if (food == 10)
			cart();
		else if (food == 11)
			return;
		// Call food_order to get the order of foods and to calculate the total amount of the order
		else
			food_order(food);
	}
}

// Function for ordering by food
void food_order(int food)
{
	if (food >= 1 && food <= 3)
		id = 1;
	else if (food >= 4 && food <= 6)
		id = 2;
	else
		id = 3;
	if ((food % 3) == 1) {
		printf("Please Enter the amount of %s\t ",m[id].menu1);
		scanf("%d", &n);
		total = total + (n * m[id].price1);
	}
	else if ((food % 3) == 2) {
		printf("Please Enter the amount of %s\t",m[id].menu2);
		scanf("%d", &n);
		total = total + (n * m[id].price2);
	}
	else if ((food % 3) == 0) {
		printf("Please Enter the amount of %s\t",m[id].menu3);
		scanf("%d", &n);
		total = total + (n * m[id].price3);
	}
}
// Function for cart

void cart()
{
	printf("\n\n--------------Cart----------------");
	char address[50];
    printf("\n Enter your table number: ");
    scanf("%s",address);
	printf("\nYour Total Order Amount is %d\n",total);
	printf("Deliver to %s",address);
	printf("\nDo You wish to order (y=1/n=0): ");
	scanf("%d", &ch);
	if (ch == 1) {
		printf("\n\nThank You for your order! Your Food is on the way.");
		exit(0);
	}
	else if (ch == 0) {
		printf("Do You want to exit (1) or Go back (0)");
		scanf("%d", &confirm);
		if (confirm == 1) {
			printf("\n Your order is canceled");
			return;
		}
		else {
			printf("\n\nThank You\n\n");
            main();
		}
	}
	else {
		printf("\nPlease Enter the correct choice\n ");
		cart();
	}
}


//Psuedo-code
int main()
{
    //asks the user how they want to search, or exits
    printf("Please enter your name ");
    scanf("%s", name);
    printf("Welcome to Food Ordering System");
    printf("Would you like to order by Restaurant(1), order by menu(2), or exit(3) \t")
    scanf("%d", search_choice);

    switch (search_choice)
    {
       case 1: {
					find_by_restaurant();
					break;
				}
				case 2: {
					find_by_menu();
					break;
				}
				case 3: {
					exit(0);
				}
				default: {
					printf("Please Enter the available choice");
					break;
				}
				}
				break;
}

//initializes the restaurants and its menu
//can be changed in the code
int rest_initialize()
{
    strcpy(m[1].restaurant, "restaurant1")
    strcpy(m[1].menu1, "menu1");
    strcpy(m[1].menu2, "menu2");
    strcpy(m[1].menu3, "menu3");
    m[1].price1 = price1;
    m[1].price2 = price2;
    m[1].price3 = price3;

    strcpy(m[2].restaurant, "restaurant2");
    strcpy(m[2].menu1, "menu1");
    strcpy(m[2].menu2, "menu2");
    strcpy(m[2].menu3, "menu3");
    m[2].price1 = price1;
    m[2].price2 = price2;
    m[2].price3 = price3;

    strcpy(m[3].restaurant, "restaurant3");
    strcpy(m[3].menu1, "menu1");
    strcpy(m[3].menu2, "menu2");
    strcpy(m[3].menu3, "menu3");
    m[3].price1 = price1;
    m[3].price2 = price2;
    m[3].price3 = price3;
}

//choosing which restaurant you want to order from
int find_by_restaurant()
{
    rest_initialize();
    printf("Please Choose a restaurant \n1) %s\n2) %s\n3) %s",
         m[1].restaurant, m[2].restaurant, m[3].restaurant);
    printf("\n4) Exit");
	printf("Please select a restaurant: \t");
	scanf("%d", &res_choice);

	if (res_choice > 4)
    {
        printf("Please enter a valid choice");
        find_by_restaurant()
    }
    else if (res_choic == 4)
    {
        main()
    }
    else
    {
        restaurants(res_choice)
    }
}

int restaurants(int res_choice)
{
    //displays the list of food available
    //first shows the name of the restaurant, then shows each menu along with its price
		printf("List of foods available ");
		printf("in %s\n\n1) %s\tBaht: %d\n2) ",
                m[res_choice].restaurant, m[res_choice].menu1, m[res_choice].price1);

		printf("%s\tBaht: %d\n3) %s\tBaht: %d\n4) ",
                m[res_choice].menu2, m[res_choice].price2,
                m[res_choice].menu3, m[res_choice].price3);

		printf("Cart\n5) Exit \nPlease Enter Your Choice\t ");
		scanf("%d", &food_choice);

		//asks the user to enter the amount of the order the user chooses, and adds it to the total
		if (food_choice == 1)
        {
			printf("Please Enter the amount of %s: ", m[res_choice].menu1);
			scanf("%d", &n);
			total = total + (n * m[res_choice].price1);
		}
		else if (food_choice == 2)
        {
			printf("Please Enter the amount of %s: ", m[res_choice].menu2);
			scanf("%d", &n);
			total = total + (n * m[res_choice].price2);
		}
		else if (food_choice == 3)
        {
			printf("Please Enter the amount of %s: ", m[res_choice].menu3);
			scanf("%d", &n);
			total = total + (n * m[res_choice].price3);
		}
		else if (food_choice == 4)
        {
			cart();
		}
		else if (food_choice == 5)
        {
			find_by_restaurant();
		}
		else
		{
			printf("Please Enter a Valid Choice\n");

		}
}

int menu_find()
{
    restaurant_initialize();
	while (1)
    {
        printf("Please choose the menu");
        printf("\n1) %s\t%d \n2) %s\t%d \n3) %s\t%d",
               m[1].menu1, m[1].price1, m[1].menu2, m[1].price2, m[1].menu3, m[1].price3);
        printf("\n4) %s\t%d \n5) %s\t%d \n6) %s\t%d",
               m[2].menu1, m[2].price1, m[2].menu2, m[2].price2, m[2].menu3, m[2].price3);
        printf("\n7) %s\t%d \n8) %s\t%d \n9) %s\t%d",
               m[3].menu1, m[3].price1, m[3].menu2, m[3].price2, m[3].menu3, m[3].price3);
        printf("\n10) Cart \n11) Exit");

		printf("\nPlease Enter Your Choice: ");
		scanf("%d", &food);

		if (food > 10) {
			printf("Please Enter the valid choice\n");
			find_by_menu();
		}
		else if (food == 10)
			cart();
		else if (food == 11)
			return;
		//call food_order to get the order of foods and to calculate the total amount of the order after every menu chosen
		else
			food_order(food);
	}
}

int food_order(food)
{
    //checks for the id of the struct the menu is in
    //e.g. number 4 in the choice is in struct 2
    if (food >= 1 && food <= 3)
		id = 1;
	else if (food >= 4 && food <= 6)
		id = 2;
	else
		id = 3;

    //checking which price to use from each struct
    if remainder of value of food divide by 3 is equal to 1 then
       print(Please Enter the amount of first menu(can be from any restaurant)
       get amount of first menu
       total=total + (amount * first menu)

    if remainder of value of food divide by 3 is equal to 2 then
       print(Please Enter the amount of second menu(can be from any restaurant)
       get amount of second menu
        total=total + (amount * second menu)

    if remainder of value of food divide by 3 is equal to 0 then
       print(Please Enter the amount of third menu(can be from any restaurant)
       get amount of Third menu
       total=total + (amount * third menu)
}

//to finalize the order and know where to deliver to
int cart()
{
    print(Please enter your table number: )
    get table number

    print(Your total order amount is (total))
    print(Delivering to(address))
    print(do you wish to order?(yes press 1/ no press 0))
    get yes/no

    if yes

        print(Thank you for your order! Your food is on the way.)

    else if no

        print(Do you want to exit press 1 or go back press 0)
        get confirm choice

    if confirm choice = exit
        print(Your order is canceled)

    else
        print(Thank you)

    else
        print(Please Enter the correct choice)
        call cart function
}
