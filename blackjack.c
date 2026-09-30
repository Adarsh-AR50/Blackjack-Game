    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    int playercard[10];
    int dealercard[10];
    int playertotal = 0;
    int dealertotal = 0;
    int playerindex = 0;
    int dealerindex = 0;
    int a;

    void welcome()                           //no parameter no return (function 1)
    {
        printf("========================= Welcome to BLACKJACK =========================\n");
    }

    void display_card(int card)              //with parameter but no return (Funtion 2)
    {
        switch (card)
        {
            case 1 : printf ("Ace\n");
            break;
            
            case 11 : printf ("Jack\n");
            break;
            
            case 12 : printf ("Queen\n");
            break;
            
            case 13 : printf ("King\n");
            break;
            
            default:
            printf("%d\n", card);
            
        }
    }

    int draw_card()                             //with return value (Funtion 3)
    {
        return rand() % 13 + 1;
    }

    int card_values(int card)                  //function 4
    {
        switch (card)
        {
            case 1:
            return 1;

            case 11:
            return 10;

            case 12:
            return 10;

            case 13:
            return 10;

            default:
            return card;
        }
    }

    void player_deal_card()
    {
        playercard[playerindex] = draw_card();
        display_card(playercard[playerindex]);
        if (card_values(playercard[playerindex]) == 1)
        {
            printf("\nIt is Ace choose 1 or 11\n");
            scanf("%d",&a);

            playertotal += a;
        }
        else
        {
            playertotal += card_values(playercard[playerindex]);
        }
        playerindex++;
    }

    void dealer_card()
    {
        dealercard[dealerindex] = draw_card();
        display_card(dealercard[dealerindex]);
        if (card_values(dealercard[dealerindex]) == 1)
        {
            printf("\nThe dealer got Ace\n");
            if(dealertotal <11)
            {
                printf ("\nThe dealer Ace value is = 11\n");
                int b = 11;
                dealertotal += b;
                printf ("The total value of Dealer is: %d",dealertotal);
                printf("\n-------------------------------\n");
                
            }
            else
            {
                printf ("\nThe dealer Ace value is = 1\n");
                dealertotal += card_values(dealercard[dealerindex]);
                printf ("The total value of Dealer is: %d",dealertotal);
                printf("\n-------------------------------\n");
            }

        }
        else
        {
            dealertotal += card_values(dealercard[dealerindex]);
            dealerindex++;
            printf("\nThe Total value of Dealer is: %d\n",dealertotal);
            printf("\n-------------------------------\n");
            
        }
        
    }

//-----------------------------------------------------------------------------------------
    int main ()
    {
        
        int r=0;
        srand(time(0));
        welcome();

        do 
        {
            int c=1;
            int bet = 0;
            int total_amount = 0;
            int winnings = 0;
            printf("-------------------------------");
            printf("\nEnter tha Amount you have to bet: \n");
            scanf("%d",&bet);
            printf("\n-------------------------------\n");
            printf("\nThe player cards are\n");
            player_deal_card();
            player_deal_card();
            printf("\nTotal value = %d\n", playertotal);
            printf("\n-------------------------------");
            if(playertotal==21)
            {
                printf("\n========== BLACKJACK ==========\n");
                printf("Player Has Won The Match");
                winnings = bet*1.5;
                total_amount = bet + winnings;
                printf("Player Won = %d", winnings);
                printf("\nThe total amount Player will get: %d",total_amount);
            }

            while (c == 1)
            {
                printf("\n1. Hit\n2. Stand\n");
                printf("\nEnter your Choice: ");
                scanf("%d", &c);
                if (c==1)
                {
                    player_deal_card();
                }
                printf("\nTotal value = %d\n", playertotal);
                printf("\n-------------------------------");
                if (playertotal > 21)
                {
                    break;
                }
            }
            if (playertotal<21)
            {
                printf("\nDealer's Turn\n");
                dealer_card();
                while(dealertotal<=17)
                {
                    dealer_card();
                }
            }
        
            //winninc section
            if(playertotal>21)
            {
                printf("\nBusted\nYou Lost\n");
                printf("You Lost all your bet: %d",bet);
            }
            else if(dealertotal>21)
            {
                printf("\nThe dealer got busted\n");
                printf("\nPlayer has won the Round");
                printf("\nPlayer Won: %d",bet);
                total_amount = bet + bet;
                printf("\nThe total amount Player will get: %d",total_amount);
            }
            else if(dealertotal<playertotal)
            {
                printf("\nPlayer has won the Round");
                printf("\nPlayer Won: %d",bet);
                total_amount = bet + bet;
                printf("\nThe total amount Player will get: %d",total_amount);
            }
            else if (dealertotal == playertotal)
            {
                printf("\nThere is draw");
                printf("\nPlayer Won: %d",total_amount);
                printf("\nThe total amount Player will get: %d",bet);
            }
            else{
                printf("\nDealer won");
                printf("You Lost all your bet: %d",bet);
            }
        
        printf("\n-------------------------------\n");
        printf("\nTo Replay Press 1\n");
        scanf("%d",&r);
        if (r==1)
        {
            playertotal = 0;
            dealertotal = 0;
        }
        }while (r==1);
    }