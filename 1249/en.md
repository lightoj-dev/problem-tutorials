# LOJ 1249 - Chocolate Thief

### Problem statement
In this problem, each test case contains `n` number of lines. Each line contains:
 `Name(n), length(l), breadth(b), height(h)`

Denoting that the person with name (n) ate the cake of the length (l), breadth (b) and height (h). Each information is separated by a `whitespace`. Each person should eat the same amount (volume) of cake which means `l*b*h` should be the same.
However, a single `thief` stole a portion from another `victim`, given that in all cases,  
```
number of thief = number of victim = 1
```
We need to print out the `name` of the `thief` and `victim` in each testcase.

**Example Output:** `Case 1: mun took chocolate from all` 

### Approach

Basically we need to find out the name associated with `higher than average volume`  and `lower than average volume` 
of consumed cake. Here, a `map` is used. It is a `key-value` pair. The `key` is the volume of the consumed cake, and the `value` is an `Object`. Which again contains two `key-value` pairs. The `key` is the name of the person and the `value` is the number of persons which consumed the exact amount of cake as the `key` of the `map` denotes. We are storing the name because as it is mentioned in the problem, there is only `one` pair of `theif-victim` in each test case. So, storing the names where `frequency` is 1 will give us the name of the `thief` and the `victim`.

If you want to learn more about javascript `Maps`, [Here is the official documentation.](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map)

```js
const tab = {
    [key]: // Amount of cake consumed
    {
        name, // Name of the person consuming the same amount of cake as the key
        frequency // Amount of people consuming the same amount fo cake 
    }
}
```

- If there is only one key, it means that everybody got the same volume of that cake
- Otherwise, we need to find out the **minimum** key and the **maximum** key, along with the associated **name**. Then print out the name of the **victim** and the **thief**

### Javascript
-----
```js
const readline = require('readline')
const rl = readline.createInterface({
    input:process.stdin
})
const userInput = []
rl.on('line',(values)=>{
    userInput.push(values)
})


rl.on('close',()=>{
    const noOfCases = parseInt(userInput[0])
    let inputPtr = 1
    for(let i=0;i<noOfCases;i++){
        let victim = ''
        let thief = ''
        let students = parseInt(userInput[inputPtr])
        let tab = {}
        for(let i = inputPtr+1 ; i< students+inputPtr+1;i++){
            let temp = userInput[i].split(" ")
            const l = parseInt(temp[temp.length-1])
            const b = parseInt(temp[temp.length-2])
            const h = parseInt(temp[temp.length-3])
            let vol = l*b*h
            let name = temp[0]
            if(tab[vol]){
                tab[vol].name = name
                tab[vol].freq++
            }
            else{
                tab[vol] = {
                    name,
                    freq:1
                }
            }
        }
        const keys = Object.keys(tab)
        if(keys.length===1){
            console.log(`Case ${i+1}: no thief`)
        }
        else{
            let smallest = parseInt(keys[0])
            let largest = parseInt(keys[1])
            victim = tab[keys[0]].name
            thief = tab[keys[1]].name
            for(let key in tab){
                if(tab[key].freq===1){
                    if(parseInt(key)<smallest){
                        smallest = parseInt(key)
                        victim = tab[key].name
                    }
                    else if(parseInt(key)>largest){
                        largest = parseInt(key)
                        thief = tab[key].name
                    }
                }
            }
            console.log(`Case ${i+1}: ${thief} took chocolate from ${victim}`)
        }
        inputPtr = inputPtr + students + 1
    }
})
```
