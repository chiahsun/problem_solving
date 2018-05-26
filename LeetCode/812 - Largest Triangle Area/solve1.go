func area(a, b, c []int) float64 {
    res := a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1])
    return math.Abs(float64(res))/2
}

func largestTriangleArea(points [][]int) float64 {
    N := len(points)
    max_area := 0.0
    for i := 0; i < N; i++ {
        a := points[i]
        
        for k := i+1; k < N; k++ {
            b := points[k]
            
            for m := k+1; m < N; m++ {
                c := points[m]
                
                cur_area := area(a, b, c)
                if cur_area > max_area {
                    max_area = cur_area 
                }
            }
        }
    }
    return max_area
}
