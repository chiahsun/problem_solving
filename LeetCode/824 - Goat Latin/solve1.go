func toGoatLatin(S string) string {
    ans := []byte("")
    suffix := []byte("a")
    for i, begin := 0, 0; i <= len(S); i++ {
        if i == len(S) || S[i] == ' ' {
            if begin < i {
                word := []byte(S[begin:i])
                vowels := "aeiouAEIOU"
                is_vowel := false
                for k := 0; k < len(vowels); k++ {
                    if word[0] == vowels[k] {
                        is_vowel = true
                        break
                    }
                }
                if is_vowel {
                    ans = append(ans, word...)
                } else {
                    ans = append(ans, word[1:]...)
                    ans = append(ans, word[0])
                }
                ans = append(ans, "ma"...)
                ans = append(ans, suffix...)
                suffix = append(suffix, 'a')
            } 
            if i < len(S) && S[i] == ' ' {
                ans = append(ans, S[i])   
            }
            begin = i+1
        }   
    }
    
    return string(ans)
}
