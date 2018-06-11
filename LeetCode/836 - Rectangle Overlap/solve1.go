func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    if rec1[2] > rec2[2] {
        rec1, rec2 = rec2, rec1
    }
    
    
    return rec2[0] < rec1[2] && isYOverlap(rec1[1], rec1[3], rec2[1], rec2[3])
}

func isYOverlap(xb, xt, yb, yt int) bool {
    if yt < xt {
        xb, xt, yb, yt = yb, yt, xb, xt
    }
    return yb < xt
}
