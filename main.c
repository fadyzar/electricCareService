/*Elictric Core Service*/
#include <stdio.h>
#include <string.h>

#define ProudctFilePath "Proudcts.bin"
#define UserFilePath "Users.bin"
#define TechnicianFilePath "Technician.bin"
int signUpTech();
int login();

FILE* userFile;
FILE* TechnicianFile;
FILE* ProudctFile;

int userCounter = 0;
int productCount = 0;
int numOfTech = 0;
int userNumber = 0;

struct product
{
    char name[10];
    int id;
    char problem[2][255];
    int prodnum;
};
struct product prod;

struct UserDetails
{
    char name[10];
    int person_id;
    char address[20];
    char PurchaseDate[11];
    int productId;
    int Km;
};
struct UserDetails user;

struct Technician
{
    char name[10];
    int tech_id;
    int productId;
    int techNumber;
    int placeKm;
};
struct Technician tech;


int printUserDetails()
{
    printf("\033[1;33m");
    userFile=fopen(UserFilePath, "rb");
    if (userFile == NULL) {
        printf("Error! opening file to read\n");
        return 0;
    }
    fread(&user, sizeof(struct UserDetails), 1, userFile);
    while (!feof(userFile))
    {
        printf("enter your CustomerNumber: %d\n", userNumber);
        printf("enter your prod id %d\n", user.productId);
        printf("enter the Purchase Date: %s\n", user.PurchaseDate);
        printf("enter your name:%s\n", user.name);
        printf("enter your person id:%d\n", user.person_id);
        printf("enter your address:%s\n", user.address);
        printf("enter your Customer Km: %d\n", user.Km);
        printf("----------------------------------\n");

        fread(&user, sizeof(struct UserDetails), 1, userFile);
    }
    fclose(userFile);
    return 0;
}
int readUserDetails()
{
    printf("\033[1;31m");
    printf("*********\n");
    userCounter = 0;
    userFile = fopen(UserFilePath, "rb");
    if (userFile == NULL) {
        printf("Error! opening file to read\n");
        printf("this is the first user !!!!\n");
        return 0;
    }
   
    fread(&user, sizeof(struct UserDetails), 1, userFile);
    while (!feof(userFile))
    {
        fread(&user, sizeof(struct UserDetails), 1, userFile);
      if (userNumber > 0)
          userCounter++;
        
    }
    printf("You have %d Customer in your company:\n", userCounter);
    fclose(userFile);

    return 0;

}
int addUserDetails()
{
    readUserDetails(); //count how many user i have

    printf("\033[1;33m");
    userNumber = userCounter + 1;
  
    printf("enter details to CustomerNumber %d:\n", userNumber);

    /*add user details*/
    userFile = fopen( UserFilePath, "ab");

    if (userFile == NULL) {
        printf("Error! opening file to write");
        // Program exits if the file pointer returns NULL.
        return 0;
    }
    printf("enter your prod id:\n");
    scanf("%d", &user.productId);
    char c2 = getchar();

    printf("enter the Purchase Date dd/mm/yyyy:\n");
    fgets(user.PurchaseDate, 11, stdin);
    user.PurchaseDate[strlen(user.PurchaseDate) - 1] = 0;


    printf("enter your name: \n");
    fgets(user.name, 10, stdin);
    user.name[strlen(user.name) - 1] = 0;

    printf("enter your person id: \n");
    scanf("%d", &user.person_id);
    char c4 = getchar();

    printf("enter your address:\n");
    fgets(user.address, 20, stdin);
    user.address[strlen(user.address) - 1] = 0;


    printf("enter your Customer Km\n");
    scanf("%d", &user.Km);
    char c3 = getchar();

    fwrite(&user, sizeof(struct UserDetails), 1, userFile);
    printf("********\n");

  
    fclose(userFile);

    return 0;

}
int searchUserID() {
    int UserId;
    printf("please enter the user id for searching:\n");
    userFile = fopen( UserFilePath, "rb");
    if (userFile == NULL) {
        printf("Error! opening file to read\n");
        printf("this is the first user !!!!\n");
        return 0;
    }
    scanf("%d", &UserId);
    fread(&user, sizeof(struct UserDetails), 1, userFile);
    while (!feof(userFile))
    {
        fread(&user, sizeof(struct UserDetails), 1, userFile);
        if (UserId == user.person_id) {
            printf("user name:%s\n", user.name);
            printf("---person id:%d\n", user.person_id);
            printf("---address:%s\n", user.address);
            printf("---CustomerNumber: %d\n", userNumber);
            printf("---prod id %d\n", user.productId);
            printf("---Purchase Date: %s\n", user.PurchaseDate);
            printf("---Customer Km: %d\n", user.Km);
            printf("----------------------------------\n");
            fclose(userFile);    return 1;
        }
    }
    printf("user not found !!!\n");
    fclose(userFile);

    return 0;

}

int readTechDetails()
{
    printf("\033[1;31m");
    printf("*********\n");
    numOfTech = 0;
    TechnicianFile = fopen(TechnicianFilePath, "rb");

    if (TechnicianFile == NULL) {
        printf("Error! opening file to read\n");
        printf("This is the first technician !!!!\n");
        return 0;
    }

    fread(&tech, sizeof(struct Technician), 1, TechnicianFile);
    while (!feof(TechnicianFile))
    {
        fread(&tech, sizeof(struct Technician), 1, TechnicianFile);
        if (tech.techNumber > 0)
            numOfTech++;
    }
    printf("You have %d technicians in your company:\n", numOfTech);
    fclose(TechnicianFile);

    return 0;
}
int printTechDetails()
{
    printf("\033[1;33m");
    TechnicianFile = fopen(TechnicianFilePath, "rb");
    if (TechnicianFile == NULL) {
        printf("Error! opening file to read\n");
        return 0;
    }
    fread(&tech, sizeof(struct Technician), 1, TechnicianFile);
    while (!feof(TechnicianFile))
    {
        printf("----------------------------------\n");
        printf("Tecnician's Number: %d\n", tech.techNumber);
        printf("Tecnician's ID %d\n", tech.tech_id);
        printf("Tecnician's name:%s\n", tech.name);
        printf("Tecnician can fix product with ID %d \n", tech.productId);
        printf("Tecnician's service area in Km: %d\n", tech.placeKm);
        printf("----------------------------------\n");

        fread(&tech, sizeof(struct Technician), 1, TechnicianFile);
    }
    fclose(TechnicianFile);

    return 0;
}
int addTechnicianDetails()
{
    readTechDetails(); //count how many technician we have

    printf("\033[1;33m");
    tech.techNumber = numOfTech + 1;
    printf("Enter details to technician number %d:\n", tech.techNumber);

    //add technicians details
    TechnicianFile = fopen(TechnicianFilePath, "ab");

    if (TechnicianFile == NULL) {
        printf("Error! opening file to write");
        // Program exits if the file pointer returns NULL.
        return 0;
    }

    printf("Enter your name:\n");
    fgets(tech.name, 10, stdin);
    tech.name[strlen(tech.name) - 1] = 0;


    printf("Enter your ID:\n");
    scanf("%d", &tech.tech_id);
    char c2 = getchar();

    printf("Enter which product id you work: \n");
    scanf("%d", &tech.productId);
    char c4 = getchar();

    printf("Enter your service area in Km\n");
    scanf("%d", &tech.placeKm);
    char c3 = getchar();

    fwrite(&tech, sizeof(struct Technician), 1, TechnicianFile);
    printf("********\n");

    fclose(TechnicianFile);
    return 0;
}
int searchTechByID() {
    int techID;
    TechnicianFile = fopen(TechnicianFilePath, "rb");
    if (TechnicianFile == NULL) {
        printf("Error! opening file to read\n");
        printf("This is the first user !!!!\n");
        return 0;
    }

    printf("Please enter the technician's ID:\n");
    scanf("%d", &techID);
    int a = getchar();
    fread(&tech, sizeof(struct Technician), 1, TechnicianFile);
    while (!feof(TechnicianFile))
    {
        fread(&tech, sizeof(struct Technician), 1, TechnicianFile);
        if (techID == tech.tech_id) {
            printf("\036[1;32m");
            printf("----------------------------------\n");
            printf("---Technician's Number is: %d\n", tech.techNumber);
            printf("---Technician's name is: %s\n", tech.name);
            printf("---Technician's Id is: %d\n", tech.tech_id);
            printf("---Technician works on prod ID: %d\n", tech.productId);
            printf("---Technician works on area:%d\n", tech.placeKm);
            printf("----------------------------------\n");
            return 0;
        }
    }
    printf("Technician isn't found\n");

    fclose(TechnicianFile);
    return 0;
}

int SearchProductId() {
    int ProductId;
    printf("please enter the Product id:\n");
    ProudctFile = fopen(ProudctFilePath, "rb");
    if (ProudctFile == NULL) {
        printf("Error! opening file to read\n");
        printf("this is the first Product !!!!\n");
        return 0;
    }
    scanf("%d", &ProductId);
    fread(&prod, sizeof(struct product), 1, ProudctFile);
    while (!feof(ProudctFile))
    {
        fread(&prod, sizeof(struct product), 1, ProudctFile);
        if (ProductId == prod.id) {
            printf("\033[1;33m");
            printf("Product name:%s\n", prod.name);
            printf("--- id:%d\n", prod.id);
            printf("--- first problem:%s\n", prod.problem[0]);
            printf("--- second problem:%s\n", prod.problem[1]);
            printf("--- num %d\n", prod.prodnum);
            printf("----------------------------------\n");
            fclose(ProudctFile);
            return 1;
        }
    }
    printf("Proudct not found\n");
    fclose(ProudctFile);

    return 0;

}
int printProdDetails()
{
    printf("\033[1;33m");
    ProudctFile = fopen(ProudctFilePath, "rb");
    if (ProudctFile == NULL) {
        printf("Error! opening file to read\n");
        return 0;
    }
    fread(&prod, sizeof(struct product), 1, ProudctFile);
    while (!feof(ProudctFile))
    {
        printf("Product name: %s\n", prod.name);
        printf("First problem :%s\n ", prod.problem[0]);
        printf("Second problem :%s\n ", prod.problem[1]);
        printf("Proudct number: %d\n", prod.prodnum);
        printf("Proudct ID: %d\n", prod.id);
        printf("********\n");
        fread(&prod, sizeof(struct product), 1, ProudctFile);
    }
    fclose(ProudctFile);

    return 0;
}
int readProdDetails()
{
    printf("\033[1;31m");
    printf("*********\n");
    productCount = 0;
    ProudctFile = fopen(ProudctFilePath, "rb");
    if (ProudctFile == NULL) {
        printf("Error! opening file to read\n");
        printf("this is the first Product !!!!\n");
        return 0;
    }
    //  n = 0;
    fread(&prod, sizeof(struct product), 1, ProudctFile);
    while (!feof(ProudctFile))
    {
        fread(&prod, sizeof(struct product), 1, ProudctFile);
        if (prod.prodnum > 0)
            productCount++;
    }
    printf("You have %d Proudcts in your company:\n", productCount);
    fclose(ProudctFile);

    return 0;

}
int addProdDetails()
{
    readProdDetails(); //count how many Products i have

    printf("\033[1;33m");
    prod.prodnum = productCount + 1;
    printf("enter details to Product Number %d:\n", prod.prodnum);

    //*add user details
    ProudctFile = fopen(ProudctFilePath, "ab");

    if (ProudctFile == NULL) {
        printf("Error! opening file to write");
        // Program exits if the file pointer returns NULL.
        return 0;
    }
    printf("enter Product Id:\n");
    scanf("%d", &prod.id);
    char c2 = getchar();

    printf("enter Product name:\n");

    fgets(prod.name, 11, stdin);
    prod.name[strlen(prod.name) - 1] = 0;

    printf("enter first problem: \n");
    fgets(prod.problem[0], 250, stdin);
    (prod.problem[0][strlen((prod.problem[0])) - 1] = 0);

    printf("enter second problem: \n");
    fgets(prod.problem[1], 250, stdin);
    (prod.problem[1][strlen((prod.problem[1])) - 1] = 0);

    prod.prodnum = productCount + 1;

    fwrite(&prod, sizeof(struct product), 1, ProudctFile);
    printf("********\n");

    fclose(ProudctFile);

    return 0;

}

int officeWork()
{
    for (;;)
    {
        printf("\033[1;32m");
        printf("***********\n");
        printf("Please choose what you want to do\n");
        printf("1. Add User Details \n");        // exist (need small fix)
        printf("2. Add Product Details\n");      // do
        printf("3. Add Technician\n");     // todo
        printf("4. print Technician Details\n"); // todo
        printf("5. print User Details\n");// have a problem
        printf("6. search User by ID\n");
        printf("7. print Product Details\n");
        printf("8. search Product ID\n");
        printf("9. Exit\n");            // exist
        printf("************\n");

        int option;
        // option= getchar();
        scanf("%d", &option);
        char c = getchar();

        switch (option)
        {
        
        case 1:
             addUserDetails();                       
            break;

        case 2:
            addProdDetails();
            break;

        case 3:
            addTechnicianDetails();
            break;

        case 4:
            readTechDetails();
            printTechDetails();
            
            break;
        case 5:
            readUserDetails();
            printUserDetails();
            break;
        case 6:
            searchUserID();
            break;
        case 7:
            readProdDetails();
            printProdDetails();
            break;
        case 8:
            SearchProductId();
            break;
        case 9:
            return 0;
        default:
            break;
        }
    }

    return 0;
}

int main()
{
 for(;;)
 {
     printf("\033[1;32m");
      printf("*********************************\n");
     printf("Please chose option: \n");
     printf("\n1.Technician\n");
     printf("\n2.office menu\n");
     printf("\n9.exit\n");
      printf("*********************************\n");
    int option;
     scanf("%d", &option);
        char c;
        c = getchar();
        
        switch (option)
        {
        case 1: signUpTech();

        break;
         case 2: officeWork();
        break;
        case 9:return 0;
        
 }
 }
 return 0;
 }
















