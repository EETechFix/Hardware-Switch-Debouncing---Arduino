Hardware Switch Debouncing - Arduino

Mechanical switch noise (switch bounce) and its effects. We’ll explore hardware debounce solutions based on resistor-capacitor filter networks and dedicated logic ICs. Switch bounces is the mechanical action that occurs when contacts come together, causing a
rapid making and breaking action before the contacts come to rest.

Every switch reads differently depending on how long or short the bounce period is. Switch bounce is undesirable. It can cause arcing, leading to degradation of the contacts through ionization and metal transfer, and excessive static in neighboring analog and digital circuits.

If unmitigated, switch bounce can cause microcontroller and other electronic circuits to see a single switch activation as comprising multiple events. The bouncing signal from a switch is often debounced using software. Although this is a low-cost solution, as shown, it may not be the best option in all cases, including systems based on performance and memory-limited microcontrollers, software developers lacking expertise in switch-related issues, or systems implemented without a microcontroller.
