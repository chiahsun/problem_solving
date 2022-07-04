import Foundation
//Solution goes in Sources
class Bob {
    static func hey(_ input: String) -> String {
        // https://www.hackingwithswift.com/example-code/strings/how-to-trim-whitespace-in-a-string
        let sentence = input.trimmingCharacters(in: .whitespacesAndNewlines)
        
        if sentence == sentence.uppercased() && sentence != sentence.lowercased() {
            return "Whoa, chill out!"
        }
        
        if sentence.hasSuffix("?") {
            return "Sure."
        }

        if sentence == "" {
            return "Fine. Be that way!"
        }
        
        return "Whatever."
    }
}
