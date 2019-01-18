func getSumSquare(n int, m map[int]int) int {
    s := strconv.Itoa(n)
    cnt := 0
    for i := 0; i < len(s); i++ {
        q := int(s[i] - '0')
        cnt += m[q]
    }
    return cnt
}


func isHappy(n int) bool {
    m := map[int] int {}
    for i := 0; i < 10; i++ {
        m[i] = i * i
    }
    slow := n
    fast := n
    for {
        if slow != 1 && fast != 1 {
            slow = getSumSquare(slow, m)
            fast = getSumSquare(getSumSquare(fast, m), m)
            if slow == fast && slow != 1 && fast != 1 {
                fmt.Println(slow, fast)
                return false
            }
        } else {
                break
        }
    }
    return true
}
