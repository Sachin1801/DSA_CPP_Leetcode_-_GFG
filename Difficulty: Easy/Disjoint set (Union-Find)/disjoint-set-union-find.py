# function should return parent of x
def find(par, x):
    # Code here
    if par[x-1] == x:
        return x
    
    
    return find(par,par[x-1])

# function shouldn't return or print anything
def unionSet(par, x, z):
    # Code here
    px, pz = find(par,x), find(par,z)
    
    par[px-1] = pz