/* Continuar da aula PONG 2/3 na Danki code minuto 10:20 */

package Pong;

import java.awt.Color;
import java.awt.Graphics;

public class Enemy {
	public int x = Game.WIDTH - 10;
	public int y = 0;
	public int w = 5;
	public int h = 30;
	public int point = 0;
	public boolean up = false; 
	public boolean down = false;
	
	public void tick() {
		if(up) {
			y-=2;
		}else if(down) {
			y+=2;
			
		}
		if(y+h >= Game.HEIGHT) {
			y = Game.HEIGHT - h;
		}else if(y<0) {
			y=0;
		}
		
	}
	public void render(Graphics g ) {
		g.setColor(new Color(250,100,100));
		g.fillRect(x, y, w, h);
	}
}