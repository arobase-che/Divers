

Implémentation de l'algorithme MD5 permettant de vérifier l'authencité d'un fichier. Elle présente un risque de sécurité, il est donc recommandé de ne plus l'utiliser dans les cas où la sécurité est importante. Elle reste cependant la fonction de hashage la plus utilisée pour hasher nos mots-de-passe sur les serveurs (combinée je l'espère avec un sel).

Ici, j'implémente deux fonction, une permettant le chiffrement d'une suite d'octet. Une autre permettant le chiffrement d'un fichier. Il n'y a pas de différence nottable dans les deux implémentations, mis-à-part le paddind. 
