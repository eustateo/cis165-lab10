# AI reflection

I used Codex to help turn my plan into C++ code and set up the tests in OnlineGDB. I explained my plan first, predicted the results for the fixed arrays by comparing their positions, and ran the tests using C++17.

One decision I made was to generate the winning digits each time the game runs. I wanted each game to give the player a new chance to match the digits. For testing, I used fixed winning digits so I could predict the exact count. The final program fills the winning array with random digits again.

In my random run, the winning digits were `8 0 9 8 5` and my input was `9 0 9 0 9`. I checked them by hand and found matches at indexes 1 and 2. The program printed `Matches: 2`, which agreed with my count and showed that the program compared the two arrays by position in that run.

I can now trace the match count myself by working through both arrays one index at a time. I still want to practice validating user input in loops and working with multidimensional arrays without making off-by-one indexing errors.
