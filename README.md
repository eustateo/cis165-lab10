# CIS-165 Lab 10: Lottery Simulation

Oscar Eustate De Jesus  
Course section: CIS-165-W099

## Initial plan

I will use one loop to fill `winningDigits` with five random digits from 0 to 9 and another loop to read five digits from the player into `player`. I want the winning digits to change from one game to the next, so I will generate them each time the program runs.

I will start the match count at zero and use a loop to check the same index in both arrays. For example, if index 2 in `winningDigits` has the same digit as index 2 in `player`, I will add one to the count. I will display all five winning digits, all five player digits, and the match count with clear labels.

## How to compile and run

In OnlineGDB, open `lottery.cpp`, choose **C++17**, and click **Run**. Enter five space-separated digits from 0 to 9, then press Enter. Repeated digits are allowed.

To run from a terminal in the same directory as `lottery.cpp`, compile with C++17 and then launch the resulting program:

```sh
g++ -std=c++17 -Wall -Wextra lottery.cpp -o lottery
./lottery
```

## Fixed-array tests

For these runs, the random draw was temporarily replaced with a fixed `winningDigits` initializer. The same comparison loop was used for each run.

| Test | Winning digits | Player digits | Prediction before Run | Actual output | Comparison |
| --- | --- | --- | --- | --- | --- |
| 1 | `7 4 9 1 3` | `4 2 9 7 3` | 2 matches at indexes 2 and 4 | Both arrays as shown, `Matches: 2` | Matched |
| 2 | `7 4 9 1 3` | `7 4 9 1 3` | 5 matches at indexes 0, 1, 2, 3, and 4 | Both arrays as shown, `Matches: 5` | Matched |
| 3 | `7 4 9 1 3` | `0 0 0 0 0` | 0 matches | Both arrays as shown, `Matches: 0` | Matched |
| 4 | `1 1 2 2 3` | `1 2 2 3 3` | 3 matches at indexes 0, 2, and 4 | Both arrays as shown, `Matches: 3` | Matched |
| 5 | `7 4 9 1 3` | `0 4 9 1 3` | 4 matches at indexes 1, 2, 3, and 4 | Both arrays as shown, `Matches: 4` | Matched |

Test 5 changes only the first player digit from test 2. This checks whether a mismatch at index 0 reduces the total while all four later positions still match.

## Final random-generation run

For the final version, the fixed `winningDigits` initializer was removed and the one-time seed and random-fill loop were restored. I ran that version in OnlineGDB using C++17.

| Winning digits | Player digits | Manual check | Program output | Comparison |
| --- | --- | --- | --- | --- |
| `8 0 9 8 5` | `9 0 9 0 9` | All winning digits are in the range 0–9. I found matches at indexes 1 and 2, for a total of 2. | `Matches: 2` | Matched |

## Code explanation

`rand()` returns a nonnegative integer. The `% 10` operation keeps the remainder after division by 10, which is a whole number from 0 through 9.

I compare the digit at each index in `winningDigits` with the digit at the same index in `player`. This makes the position part of the match. In test 1, I identified matches at indexes 2 and 4. Starting at zero, the count after each of the five comparisons is `0, 0, 1, 1, 2`.

C++ arrays start at index 0. With `SIZE` equal to 5, `index < SIZE` lets the loop use indexes 0 through 4 and prevents it from accessing index 5, which is outside the array.

The fixed tests showed how the program handles partial matches, all matches, and zero matches. The repeated-digits test specifically showed that `winningDigits[index] == player[index]` counts duplicate digits only at positions where both arrays have the same digit.
