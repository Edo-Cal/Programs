/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.changedriveletter;

import JFrame.NewJFrame;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Utente
 */
public class ChangeDriveLetter {

    public static void main(String[] args) {
        
        NewJFrame.main(args);
        
    }
    
    public static void updateVolumes(){
    
        File listVolume=new File("listVolume.lnk");
       String listPath=listVolume.getAbsolutePath();
        
        try {
            
            ProcessBuilder pb = new ProcessBuilder("cmd", "/c", listPath);
            Process p = pb.start();
            p.waitFor();
        } catch (IOException ex) {
            Logger.getLogger(NewJFrame.class.getName()).log(Level.SEVERE, null, ex);
        } catch (InterruptedException ex) {
            Logger.getLogger(ChangeDriveLetter.class.getName()).log(Level.SEVERE, null, ex);
        }
    
    }
    
}
