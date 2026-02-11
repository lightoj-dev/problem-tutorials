# Run Rate 1

## Problem Summary

In a 50-over ODI cricket match:

- Total balls = 50 × 6 = 300
- We are given:
  - r1 → Opponent’s total runs
  - r2 → Current runs of batting team
  - B → Remaining balls

We need to calculate:

1. Current Run Rate (CRR)
2. Required Run Rate (RRR)

Each value must be printed with exactly two digits after the decimal point.

---

## Important Cricket Rules

- 1 over = 6 balls
- To win, the batting team must score at least 1 run more than the opponent.
- Balls played = 300 - B

---

## Formula Explanation

### 1. Current Run Rate (CRR)

Current Run Rate is calculated based on runs scored and balls already played.

CRR = (r2 × 6) / balls_played

Where:

balls_played = 300 - B

We multiply by 6 because run rate is calculated per over (6 balls).

---

### 2. Required Run Rate (RRR)

First, calculate runs needed to win:

runs_needed = (r1 + 1) - r2

If runs_needed becomes negative, we set it to 0 because the team has already won.

Then,

RRR = (runs_needed × 6) / B

This calculates how many runs per over are required in the remaining balls.

---

## Edge Cases Considered

- If balls_played = 0, CRR is set to 0.00.
- If B = 0, RRR is set to 0.00.
- If the team already won, required run rate becomes 0.00.

---

## C++ Implementation

```cpp
//------ Contributor ~ --------//
//------ MD. S. M. Sarowar Hossain --------//
//------ Varendra University --------//

#include <iostream>
#include <iomanip> // for setprecision and fixed value

using namespace std;

int main()
{
    int n;
    cin >> n; //test case

    while (n--)
    {
        long long r1, r2, B;
        cin >> r1 >> r2 >> B; //three required variables 

        long long ball_played = 300 - B; // 50 overs = 50 * 6 = 300 balls

        double current_run_rate = 0.0; //if no ball played, crr = 0
        if (ball_played > 0){
            current_run_rate = (r2 * 6.0) / ball_played; //if balls played, calculate the RR
               }
        double run_needed = (r1 + 1) - r2;
        if (run_needed < 0) {
            run_needed = 0; //if the player get 2, 3, 4 or 6 runs when 1 run is required,
                            // the run_needed calculation return (-)negative value, so we need to
                            // set the value to 0, cause already won the match.
              }
        double required_run_rate = 0.0;
        if (B > 0) {
            required_run_rate = (run_needed * 6.0) / B;
            }
        cout << fixed << setprecision(2)
             << current_run_rate << " "
             << required_run_rate << endl;
    }

    return 0;
}
