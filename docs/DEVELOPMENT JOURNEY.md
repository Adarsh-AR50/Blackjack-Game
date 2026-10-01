# Blackjack

<br>

## Day – 1 (08-07-2026)

I am making a game called Blackjack. It is a game of skill.

I didn’t know how to play this game, so I watched videos on YouTube to understand what the game is, what the rules are, and how to play it. After watching the videos, I got a basic idea of how to start and what to do. I still had some questions, but I thought that after making the game, all the problems would be solved automatically. Then I started to code.

The face cards have their usual values. Jack, Queen, and King hold 10 points, and Ace is a special card that holds 1 or 11 points depending on what the player chooses.

**For a win:**

- Your points are greater than the dealer’s points.
- The dealer’s points are greater than 21.
- If your score is equal to the dealer’s score, it is a draw.
- If your score is higher than 21, you are busted and lose.

Now let’s code.

We want a random integer, so we use `rand()`, which returns a random integer.

For that, we use new header files:

```c
#include <stdlib.h>
#include <time.h>
```

A Blackjack game needs random cards, so we use `rand()`. This gives a random integer. To give a range for random numbers, we use `%`. We want 13 possible random numbers, so we use `%13`. This gives numbers from 0–12, but we want numbers up to 13, so we use `+1`. The range therefore becomes `rand() % 13 + 1`.

`rand()` = Pseudo-random number — a sequence of values that appears statistically random.

The code looks like:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int number = rand() % 13 + 1;
    printf("%d", number);
}
```

Here, s is the seed, and `rand()` generates random numbers. The seed we use is time.

This type of code was new to me, so I learned this in Day 1.

Now we generated random numbers from 1–13, but we have to give them names: 1, 11, 12, and 13 = Ace, Jack, Queen, and King respectively.

<br>

----------------------------------------------------------------------

<br>

## Day – 2 (11-07-2026)

As I left the work on Day 1, I had to complete the work of giving names to the card values, so I used `switch`.

Now the names of the cards will be used again and again. Instead of using `switch` multiple times, I decided to make a function to display the names.

I made two functions: one for displaying the welcome screen and the second one for displaying the card values.

For now, I am displaying two cards for the player and two cards for the dealer.

After this, the work of drawing a card was coming up again and again, so I decided to make a function for drawing a card. Now I have three functions.

**Learned in Day 2:**

Functions = A function is a named block of code that performs a specific task. We can call it whenever we need that task instead of writing the same code repeatedly.

- Function without a parameter
- Function with a parameter
- Function with a return value

<br>

----------------------------------------------------------------------

<br>

## Day – 3 (17-07-2026)

After giving names to the cards, the program was displaying the names, but it was forgetting the previous card value.

For example, I draw the first card and it is 8. After the second draw, the random number generated is 5. Now the program forgot what the first card value was. For this, I gave the variables names like `playercard1` and `playercard2`.

After taking a break, I was thinking that to play a real game, we need a lot of player cards, so I thought about making an array for that.

A `total` variable is used to calculate the total points.

<br>

----------------------------------------------------------------------

<br>

## Day – 4 (19-07-2026)

I created an array. The starting two cards are showing properly. I used an `if` statement for Stand and Hit, but it was not working, even though there was no error.

I was going in the wrong direction.

Now I had to make my first game logic. In this, all cards have different values, meaning different points. I had to make a function for point calculation.

For now, I am taking the value of Ace as 1 for easy calculation.

For making the function, I used `switch` because the value of J, Q, and K is 10.

And Ace = 1.

After point calculation, the game rule asks the player to choose Hit or Stand, so I used a `while` loop.

This was working, but there was one issue: after Stand was chosen, a card was still being drawn and displayed.

I removed the issue because I had forgotten to use an `if` condition.

Now, if the user chooses Hit and the total goes above 21, the program will print Busted — You Lost.

<br>

----------------------------------------------------------------------

<br>

## Day – 5 (21-07-2026)

I made some variables global (`playercard`, `total`, `i`).

In this function, I placed the lines of code that were doing all the work — drawing, displaying, and calculating the total. From the loop, there was an `if` condition in which I called that function.

The name of the function is `deal_card`, which will deal a player card.

Now the player section is done. I have to work on the dealer section. I thought about reusing the function again, but I couldn’t because the total would be miscalculated. Now I have to make a function for the dealer, and I have to change some old variable names because I had used them as temporary names. For reading the code properly, meaningful variable names should be used. That was it for today.

<br>

----------------------------------------------------------------------

<br>

## Day – 6 (25-07-2026)

I made the functions for drawing the dealer’s card, displaying it, and counting the total. All the functions are done.

I changed the names of some variables because they were creating confusion while running or understanding the code.

I made the logic for Ace, which will ask for 1 or 11 because it is a special card.

After completing the dealer card draw program, I made the winning section, which will tell who the winner is.

<br>

----------------------------------------------------------------------

<br>

## Day – 7 (26-07-2026)

As I opened VS Code and ran my code to check what I had done and what I should improve or whether I should move forward, I found out that the last part of the Ace logic — the special card for which I had made the 1 or 11 option — had not been saved.

I was disappointed by that, and the link I had used to create it was broken. My mind was not getting the pace needed to make the program.

I made the logic for the Ace card.

<br>

----------------------------------------------------------------------

<br>

## Day – 8 (29-07-2026)

The logic of Ace should be changed because the dealer’s choice was being asked of the player. For that, I had to change the Ace logic in the program.

By trying again and again, the code was not working properly. It was not showing an error, but the output was not as expected.

Seven days ago, I tried, I failed, but I came back with a solution. Today, I did not get any solution, so I am taking a break. Let’s try another day.

<br>

----------------------------------------------------------------------

<br>

## Day – 9 (30-07-2026)

New day, new beginning. I solved the issue. The main issue was that I had forgotten that the word `else` exists in this world. Finally, I removed the issue from the program, and it is working properly.

Now, for a rematch, I used a `do-while` loop. Now let’s implement that.

The work of the `do-while` loop is done, and it is working properly.

<br>

----------------------------------------------------------------------

<br>

## Day – 10 (30-09-2026)

I have come back after many days, so first I went through my code again to understand what I was doing, where I had stopped, and what I had done last time. After understanding everything again, I knew what I had to do next.

After compiling the program, I was not satisfied with the output, so I changed the code so that after compiling, it should look clean, good, and easy to understand.

I realized this when I was explaining to my friend how my code works. He was confused by the output because it looked a little messy, so I used hyphens and equal signs to make it look clean and clear.

I added a betting system. The player will be able to bet, and the program will tell how much the player wins and how much the player will get in total.

I checked all the rules and found that everything was working properly without errors or bugs.

<br>

----------------------------------------------------------------------
