func numJewelsInStones(J string, S string) int {
    m := map[int32]int{}
    for _, v := range(J){
        m[v]++
    }
    res := 0
    for _, v := range(S){
        res += m[v]
    }
    return res
}
