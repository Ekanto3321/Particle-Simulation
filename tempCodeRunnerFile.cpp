float energyRatio = fmin(penergy / threshold, 1.0f);  
                p[i].color = {
                    (unsigned char)(energyRatio * 255),             //R
                    0,                                              //G
                    (unsigned char)((1.00f - energyRatio) * 255),   //B
                    255                                  
                };