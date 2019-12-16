/* Continuar da aula PONG 2/3 na Danki code minuto 10:20 */

package Pong;
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;

import javax.swing.JFrame;

public class Game extends Canvas implements Runnable, KeyListener{
	public static JFrame frame;
	private static final long serialVersionUID = -5968316317471499065L;
	public static int HEIGHT = 160;
	public static int WIDTH = 240;
	public static int SCALE = 4;
	public static Player player = new Player();
	public static Enemy enemy = new Enemy();
	//public static int dif;
	//arg of ball is difficulty 3 is medium, 2 is easy and 4 is hard
	public static Ball ball;// = new Ball(3);
	public int pause = 0;
	public boolean begin = true;
	public BufferedImage image = new BufferedImage(WIDTH,HEIGHT,BufferedImage.TYPE_INT_RGB);	
	
	
	
	public Game(){
		this.setPreferredSize(new Dimension(WIDTH*SCALE,HEIGHT*SCALE));
		this.addKeyListener(this);
	}
	public static void main(String[] args) {
		Game game = new Game();
		frame = new JFrame("Pong");
		frame.setResizable(false);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.add(game);
		frame.pack();
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);
		new Thread(game).start();
	}
	public void tick() {
		if(!begin) {
			player.tick();
			enemy.tick();
			ball.tick();
		}
		
	}
	public void render() {
		BufferStrategy bs = this.getBufferStrategy();
		if(bs == null) {
			this.createBufferStrategy(3);
			return;
		}
		Graphics g = image.getGraphics(); 
		g.setColor(new Color(100,100,100));
		g.fillRect(0, 0, WIDTH, HEIGHT);
		if(begin) {
			g.setColor(Color.WHITE);
			g.setFont(new Font("Arial", 1, 30));
			g.drawString("PONG", WIDTH/2 - 45, 30);
			g.setFont(new Font("Arial", 1, 13));
			g.drawString("Press 1, 2 or 3 to set the difficulty", 10, 100);
		}else {
			player.render(g);
			enemy.render(g);
			ball.render(g);
			g.setFont(new Font("Arial", 1, 13));
			g.drawString(Integer.toString(player.point), 20, 10);
			g.setFont(new Font("Arial", 1, 13));
			g.drawString(Integer.toString(enemy.point), WIDTH-20, 10);
		}
		if(pause == 1) {
			g.setColor(new Color(100,100,100));
			g.fillRect(0, 0, WIDTH, HEIGHT);
			g.setColor(Color.WHITE);
			g.setFont(new Font("Arial", 1, 30));
			g.drawString("PONG", WIDTH/2 - 45, 30);
			g.setFont(new Font("Arial", 1, 13));
			g.drawString("Press Q to stop or space to resume", 10, 100);
		}
		g = bs.getDrawGraphics();
		g.drawImage(image, 0, 0, WIDTH*SCALE, HEIGHT*SCALE, null);
		bs.show();
		
		//System.out.println("fred");
	}
	public static void hit(int who) {
		if(who == 1) {
			player.point ++;
		}else {
			enemy.point ++;
		}
	}
	
	@Override
	public void run() {
		while(true) {
			switch(pause) {
				case 0:
					tick();
					render();
					break;
				case 1:
					render();
					break;
			}
			try {
				Thread.sleep(1000/60);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
//		if(e.getKeyCode() == KeyEvent.VK_UP) {
//			player.up = true;
//		}else if(e.getKeyCode() == KeyEvent.VK_DOWN) {
//			player.down = true;
//		}else if(e.getKeyCode() == KeyEvent.VK_W) {
//			enemy.up = true;
//		}else if(e.getKeyCode() == KeyEvent.VK_S) {
//			enemy.down = true;
//		}
		if(begin) {
			switch(e.getKeyCode()) {
				case KeyEvent.VK_1:
					ball = new Ball(2);
					begin = false;
					//System.out.println("start");
					break;
				case KeyEvent.VK_2:
					ball = new Ball(3);
					begin = false;
					break;
				case KeyEvent.VK_3:
					ball = new Ball(4);
					begin = false;
					break;
			}
		}
		switch(e.getKeyCode()) {
		case KeyEvent.VK_UP:
			player.up = true;
			break;
		case KeyEvent.VK_DOWN:
			player.down = true;
			break;
		case KeyEvent.VK_W:
			enemy.up = true;
			break;
		case KeyEvent.VK_S:
			enemy.down = true;
			break;
		case KeyEvent.VK_SPACE:
			pause = ((pause == 0) ? 1 : 0);
		}
		if(pause == 1) {
			if(e.getKeyCode() == KeyEvent.VK_Q) {
				System.exit(0);
			}
		}
		
	}
	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
//		if(e.getKeyCode() == KeyEvent.VK_UP) {
//			player.up = false;
//		}else if(e.getKeyCode() == KeyEvent.VK_DOWN) {
//			player.down = false;
//		}else if(e.getKeyCode() == KeyEvent.VK_W) {
//			enemy.up = false;
//		}else if(e.getKeyCode() == KeyEvent.VK_S) {
//			enemy.down = false;
//		}
		switch(e.getKeyCode()) {
			case KeyEvent.VK_UP:
				player.up = false;
				break;
			case KeyEvent.VK_DOWN:
				player.down = false;
				break;
			case KeyEvent.VK_W:
				enemy.up = false;
				break;
			case KeyEvent.VK_S:
				enemy.down = false;
				break;
		}
		
	}
	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}
}
