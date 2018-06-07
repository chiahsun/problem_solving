var (
    hours_time = [...]int {1, 2, 4, 8}
    mins_time = [...]int {1, 2, 4, 8, 16, 32}
)

func readBinaryWatch(num int) []string {
    leds := make([]bool, 10)
    ans := make([]string, 0)
    generate(leds, 0, num, &ans)
    return ans
}

func get_hour(leds []bool) int {
    hour := 0
    for i := 0; i < 4; i++ {
        if leds[i] {
            hour += hours_time[i]
        }
    }
    return hour
}

func get_minute(leds []bool) int {
    min := 0
    for i := 4; i < 10; i++ {
        if leds[i] {
            min += mins_time[i-4]
        }
    }
    return min
}

func get_time(leds []bool) string {
    return fmt.Sprintf("%d:%02d", get_hour(leds), get_minute(leds))
}

func valid(leds []bool) bool {
    hour := get_hour(leds)
    if hour > 11 {
        return false
    }
    min := get_minute(leds)
    if min > 59 {
        return false
    }
    return true
}

func generate(leds []bool, cur int, lefts int, ans* []string) {
    if lefts == 0 {
        *ans = append(*ans, get_time(leds))
        return
    }
    if lefts > (len(leds) - cur) {
        return
    }
    for i := cur; i < len(leds); i++ {
        leds[i] = true
        if valid(leds) {
            generate(leds, i+1, lefts-1, ans)
        }
        leds[i] = false
    }
}
