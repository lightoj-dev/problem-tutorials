# LOJ 1311 - Unlucky Bird
---

Given the values v<sub>train 1</sub>, v<sub>train 2</sub>, v<sub>bird</sub>, a<sub>train 1</sub>, a<sub>train 2</sub>, calculate the distance covered by the trains when they saw each other and also how much distance the bird covered while flying in between them.

## Solution

We are given the __deaccelaration__ and __velocity__ of both the trains. If we divide the __velocity__ by __deaccelaration__, __t<sub>train</sub> = v<sub>train</sub>/a<sub>train</sub>__, we can obtain the __time__, __t<sub>train</sub>__, taken by each individual train to stop. The __flight time__ of the bird (_when the trains noticed one another and pulled break_) will be  the __maximum__ between these two trains because the bird did not fly any shorter duration than the collision time or else it would live and could easily fly away from the tracks. The bird died in between the trains, meaning that it kept flying until the train that took longer to stop had finally killed it. Now since the bird can take turns swiftly, we only need to plug into __d<sub>bird</sub> = v<sub>bird</sub> * t<sub>bird</sub>__, and get __d<sub>bird</sub>__, the distance covered by the bird. And for the total distance covererd by trains we just need to __sum__ the distance covered by each individual trains, __d<sub>train</sub> = v<sub>train</sub> * t<sub>train</sub> - 1/2 * a<sub>train</sub> * t<sup>2</sup>__ and then __d</sub>total</sub> = d<sub>train 1</sub> + d<sub>train 2</sub>__.

The above implementation is `accepted`.

## Solution in C
```c
#include <stdio.h>

int main(){
    int testCase;
    scanf("%d", &testCase);
    double v1,v2,v3,a1,a2,t1,t2,t3, bird, trains;
    for(int i = 1; i <= testCase; i++){
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
        t1 = v1/a1;
        t2 = v2/a2;
        t3 = t1;
        if(t1 < t2)
            t3 = t2;
        bird = v3 * t3;
        trains = v1 * t1 - .5 * a1 * t1 * t1;
        trains += v2 * t2 - .5 * a2 * t2 * t2;
        printf("Case %d: %.10lf %.10lf\n", i, trains, bird);

    }
    return 0;
}
```

