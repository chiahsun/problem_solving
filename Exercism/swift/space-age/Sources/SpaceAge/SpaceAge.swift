//Solution goes in Sources
class SpaceAge {
    var seconds: Double
    
    var onMercury: Double { onEarth / 0.2408467 }
    
    var onVenus: Double { onEarth / 0.61519726 }

    var onEarth: Double { seconds / 31557600 }
    
    var onMars: Double { onEarth / 1.8808158 }
    
    var onJupiter: Double { onEarth / 11.862615 }
    
    var onSaturn: Double { onEarth / 29.447498 }
    
    var onUranus: Double { onEarth / 84.016846 }
    
    var onNeptune: Double { onEarth / 164.79132 }
    
    init(_ seconds: Double) {
        self.seconds = seconds
    }
}

// See: https://exercism.org/tracks/swift/exercises/space-age/solutions/n8henrie for a cached optimized solution
