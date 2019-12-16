/* Continuar da aula PONG 2/3 na Danki code minuto 10:20 */

package Pong;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;


public class Ball {
	public int x;
	public int y;
	public int w;
	public int h;
	Random random = new Random();
	
	public int speed = 1;
	public int dx;
	public int dy;
	public int dif;
	
	public Ball(int dif) {
		this.dif = dif;
		start();
//		dirX();
//		dirY();
		System.out.println(dif);
	}
	
	public void dirX() {
		dx = ((random.nextInt(2) == 0) ? -1 : 1);
		dx *= random.nextInt((dif > 0) ? dif : 3) + 1;
	}
	
	public void dirY() {
		dy = ((random.nextInt(2) == 0) ? -1 : 1);
		dy *= random.nextInt((dif > 0) ? dif : 3) + 1;
	}
	
	public void start() {
		this.x = Game.WIDTH/2;
		this.y = Game.HEIGHT/2;
		this.w = 5;
		this.h = 5;
		dirX();
		dirY();
	}
	
	public void collision() {
		//pontuação
		if(x+w > Game.WIDTH) {
			start();
			Game.hit(1);
		}else if(x < 0) {
			start();
			Game.hit(0);
		}
		//reflexão
		if(y+h > Game.HEIGHT) {
			//this.y -= 5;
			this.dy *= -1;
			//dirX();
			dx = ((dx < 0) ? ((random.nextInt((dif > 0) ? dif : 3) + 1)*-1) : random.nextInt((dif > 0) ? dif : 3) + 1);
		}else if(y-h < 0) {
			//this.y += 5;
			this.dy *= -1;
			//dirX();
			dx = ((dx < 0) ? ((random.nextInt((dif > 0) ? dif : 3) + 1)*-1) : random.nextInt((dif > 0) ? dif : 3) + 1);
		}
		//hit
		if(x <= Game.player.x + Game.player.w && y<Game.player.y + Game.player.h && y> Game.player.y) {
			dx *= -1;
			dirY();
		}else if(x+w >= Game.enemy.x && y < Game.enemy.y + Game.enemy.h && y> Game.enemy.y) {
			dx *= -1;
			dirY();
		}
	}
	
	public void tick() {
		this.x += dx*speed;
		this.y += dy*speed;
		collision();
	}
	
	public void render(Graphics g) {
		g.setColor(new Color(255,255,255));
		g.fillOval(x, y, w, h);
	}
	
}
