func findDuplicate(paths []string) [][]string {
    m := map[string] []string{}
    res := [][]string{}
    for _, v := range paths {
        var files []string = strings.Split(v, " ")
        var root string = files[0]
        for _, f := range files[1:] {
            l := strings.Index(f, "(")
            r := strings.Index(f, ")")
            var name string = root + "/" + f[:l]
            var content string = f[l+1:r]
            m[content] = append(m[content], name)
        }
    }
    for _, v := range m {
        if len(v) > 1 {
            res = append(res, v)
        }
    }
    return res
}
