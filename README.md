# managerClient

#Indications recu pour le projet:


- Le système consiste principalement en un gestionnaire et en plusieurs clients.
- Différents types d’événements sont reçus par le gestionnaire et doivent être distribués à des clients.
- Le gestionnaire ne connaît pas tous les types de clients.
- Le gestionnaire ne connaît pas tous les types d’événements.
- Chaque client sait comment identifier les événements qu’il désire traiter (par exemple avec un identifiant).
- À l’initialisation, les clients doivent s’enregistrer auprès du gestionnaire. Un mécanisme doit donc être implémenté à cette fin. 
- Les événements peuvent être, par exemple, de type: GPS Location,Motion detection,Cellular connection change,Battery state change, …
-Lorsqu’un client reçoit un événement, il pourrait en théorie devoir faire des opérations qui demandent beaucoup de temps. Il est donc primordiale que les clients n’exécutent pas ces opérations tout en bloquant la thread du gestionnaire. Il faut donc prévoir un mécanisme qui ne bloque pas le gestionnaire. L’implémentation de telles opérations n’est pas requise pour le test. 
-Les clients doivent logger dans la console chaque events qu’ils ont traité.
-Le gestionnaire peut s’exécuter sur le thread principal (main).
-Le programme doit pouvoir se terminer de manière à ne pas interrompre les opérations/logging d’un client. 
#Compilation

Le programme peut être executé par les commandes :
- `cmake CMakeLists.txt`
- `make`

Le programme n'a aucune librairies externes à installer, mais nécessite toutefois C++20.


#Execution

Le programme instantie dans sa version actuelle un système gestionnaire et 4 instances de systèmes clients, qui sont reliés au système gestionnaire. Le gestionnaire lit ensuite, soit par socket, ou par générateur de nombre aléatoires (Voir `src/manager.cpp` pour l'emplacement du code), des tickets d'événements, qui sont ensuite transférés aux clients pour éxécution de tâches.

![Représentation de trace de terminal d'execution](img/example.png?raw=true "Terminal view")

#Erreurs connus
- Dans sa version actuelle, le système de multi-threading peut se tromper et instancier plus d'un thread pour un client.
- Seuls 2 types de signaux d'interruption ont été implantés.