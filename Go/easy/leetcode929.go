func numUniqueEmails(emails []string) int {
    m := map[string]bool{}
    for _, v := range(emails){
        i := strings.Index(v, "@")
        local := v[:i]
        domain := v[i:]
        //i = strings.Index(local, "+")
        if i = strings.Index(local, "+"); i != -1{
            local = local[:i]
        }
        for i = strings.Index(local, "."); i != -1;{
            head := local[:i]
            tail := local[i+1:]
            local = head + tail
            i = strings.Index(local, ".")
        }
        m[local + domain] = true
    }
    return len(m)
}
