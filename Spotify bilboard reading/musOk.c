#include <stdio.h>
#include <string.h>
#include "leitura.hpp"
#include <stdlib.h>

int musOk(Musica *mus, Menu *mn) {
    double acust=0.5, danc=0.5, expl=1.0;
    if(mus->ano >= mn->anoI && mus->ano <= mn->anoF){ /*Verifica ano antes de tudo*/
        if(strcmp(mn->acusticaR, "Y")==0){
            if(strcmp(mn->dancavelR, "Y")==0){
                if(strcmp(mn->explicitaR, "Y")==0){ /*Acustica, dancavel e explicita*/
                    if(mus->acustica>0.5) { /*acustica?*/
                        if(mus->dancavel>0.5) { /*dancavel?*/
                            if(mus->explicito>=1.0){    /*explicito*/
                                return(1);
                            } else {
                                return(0);
                            }
                        } else {
                            return(0);
                        }
                    } else {
                        return(0);
                    }
                } else { /*Acustica e dancavel, n explicito*/
                    if(mus->acustica>0.5) {
                        if(mus->dancavel>0.5) {
                            if(mus->explicito<1.0){
                                return(1);
                            } else {
                                return(0);
                            }
                        } else {
                            return(0);
                        }
                    } else {
                        return(0);
                    }
                }
            } else { /*Acustica, n dancavel, explicito a definir*/
                if(strcmp(mn->explicitaR, "Y")==0){ /*Acustica, n dancavel e explicita*/
                    if(mus->acustica>0.5) {
                        if(mus->dancavel<0.5) {
                            if(mus->explicito>=1.0) {
                                return(1);
                            } else {
                                return(0);
                            }
                        } else {
                            return(0);
                        }
                    } else {
                        return(0);
                    }
                } else { /*Somente acustica*/
                    if(mus->acustica>0.5) {
                        if(mus->dancavel<0.5) {
                            if(mus->explicito<1.0) {
                                return(1);
                            } else {
                                return(0);
                            }
                        } else {
                            return(0);
                        }
                    } else {
                        return(0);
                    }
                }
            }
        } else { /*n acustica*/
            if(strcmp(mn->dancavelR, "Y")==0){
                if(strcmp(mn->explicitaR, "Y")==0){ /*Nao acustica, dancavel e explicita*/
                    if(mus->acustica<0.5) {
                        if(mus->dancavel>0.5) {
                            if(mus->explicito>=1.0) {
                                return(1);
                            } else {
                                return(0);
                            }
                        } else {
                            return(0);
                        }
                    } else {
                        return(0);
                    }
                } else { /*Somente dancavel*/
                    if(mus->acustica<0.5) {
                        if(mus->dancavel>0.5) {
                            if(mus->explicito<1.0) {
                                return(1);
                            } else {
                                return(0);
                            }
                        } else {
                            return(0);
                        }
                    } else {
                        return(0);
                    }
                }
            } else { /*Nem acustica nem dancavel*/
                if(strcmp(mn->explicitaR, "Y")==0){ /*somente explicita*/
                    if(mus->acustica<0.5) {
                        if(mus->dancavel<0.5) {
                            if(mus->explicito>=1.0) {
                                return(1);
                            } else {
                                return(0);
                            }
                        } else {
                            return(0);
                        }
                    } else {
                        return(0);
                    }
                } else { /*nem acustica, nem dancavel, nem explicita*/
                    if(mus->acustica<0.5) {
                        if(mus->dancavel<0.5) {
                            if(mus->explicito<1.0) {
                                return(1);
                            } else {
                                return(0);
                            }
                        } else {
                            return(0);
                        }
                    } else {
                        return(0);
                    }
                }
            }
        }
    } else {
        return(0);
    }
}
