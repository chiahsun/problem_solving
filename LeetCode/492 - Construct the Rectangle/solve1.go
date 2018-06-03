func constructRectangle(area int) []int {
    for a := int(math.Sqrt(float64(area))); a > 1; a-- {
        if area % a == 0 {
            return []int{area/a, a}
        }
    }
    return []int{area, 1}
}
