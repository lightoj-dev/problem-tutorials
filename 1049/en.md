# LightOJ 1049 - One Way Roads

## Brief Description of the Problem

There are `n` cities and they were connected by `n` two-way roads in the ring in such way that each city was connected directly to exactly two other cities, and from each city it was possible to get to any other city. Government changed those two-way roads and made them one-way roads. Now, you are given those `n` one-way roads directions and also the cost with each road, you can change the direction of road by the cost associated with it. You need to change the directions of the roads in such way so that from every city you can get to any other. What is the minimum amount of money by which you can do this?

## Input

Input starts with an integer `T` (≤ 200), denoting the number of test cases.

Each case starts with a blank line and an integer `n` (3 ≤ n ≤ 100) denoting the number of cities (and roads). Next `n` lines contain description of roads. Each road is described by three integers `ai`, `bi`, `ci` (1 ≤ ai, bi ≤ n, ai ≠ bi, 1 ≤ ci ≤ 100) - road is directed from city `ai` to city `bi`, redirecting the direction/traffic costs `ci`.

## Output

For each case of input you have to print the case number and the smallest amount of money the government should spend on the redirecting of roads so that from every city you can get to any other.


## Solution

