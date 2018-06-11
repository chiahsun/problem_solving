func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    return isOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) && isOverlap(rec1[1], rec1[3], rec2[1], rec2[3]) 
}

func isOverlap(xlo, xhi, ylo, yhi int) bool {
    if yhi < xhi {
        xlo, xhi, ylo, yhi = ylo, yhi, xlo, xhi
    }
    return ylo < xhi
}
