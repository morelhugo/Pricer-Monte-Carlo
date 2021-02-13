# Pricer-Monte-Carlo

## Abstract

Le but de notre code est de calculer le prix d'une option et ses grecs (sensibilités du prix de l'option à ses paramètres) via Monte-Carlo. Pour cela nous utilisons tout d'abord, les formules de Black and Scholes (B&S), pour calculer le prix de nos options et des grecs comme point d'ancrage pour la vérification du Monte-Carlo et aussi pour calculer l'erreur d'estimation des simulations (l'intervalle de confiance). Nous simulons ensuite via Monte-Carlo, N simulations mouvements Browniens géométriques pour retrouver notre prix ou bien nos sensibilités delta (**∆**) et gamma (**Γ**) sous Black and Scholes en formule fermée.

Plusieurs classes ont été créées pour implémenter notre code. Concernant l'architecture (voir Excel "ArchitectureProjet.xlsx") notre code s'articule autour de trois grands axes :
- Un axe `Loi`
- Un axe **Pay-off**
- Un axe Monte-Carlo

