//
//  ViewController.swift
//  SwiftGoose
//
//  Created by Gabriel Valky on 12/25/20.
//

import UIKit

enum MapHint {
    case none
    case stop
    case up
    case down
    case left
    case right
}

class ViewController: UIViewController {
    var timerGame: Timer? = nil
    var timerSound: Timer? = nil
    let cdman = CdmanWrapper()
    @IBOutlet weak var image: UIImageView!
    var toneTimeout = 0
    var map = [[MapHint]]()
    var lastPos:CdmanPos = CdmanPos(x: 0, y: 0)
    
    override var shouldAutorotate: Bool {
        return true
    }
    
    override func viewDidLoad() {
        let value = UIInterfaceOrientation.landscapeLeft.rawValue
        UIDevice.current.setValue(value, forKey: "orientation")
        
        super.viewDidLoad()
        
        cdman.initApp()
        
        self.timerGame = Timer.scheduledTimer(timeInterval: 0.03, target: self, selector: #selector(self.onTimerGame), userInfo: nil, repeats: true)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        guard let allTouches = event?.allTouches else { return }
        
        for touch in allTouches {
            let touchPoint = touch.location(in: self.image)
            let px = Int(touchPoint.x / self.image.frame.width * 640)
            let py = Int(touchPoint.y / self.image.frame.height * 350)
            navigateToPoint(x: px, y: py)
            break;
        }
    }

    @objc func onTimerGame(_ timer: Timer) {
        navigate()
        cdman.run()
        image.image = imageFromRGBBitmap( data:cdman.getImageData(), width:640, height:350)
    }

    private func imageFromRGBBitmap(data: Data, width: size_t, height: size_t) -> UIImage? {
        let bitsPerComponent: size_t = 8
        let bitsPerPixel: size_t = 32
        let rgbColorSpace = CGColorSpaceCreateDeviceRGB()
        let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.noneSkipLast.rawValue)
            .union(.byteOrder32Big)
        
        let providerRef:CGDataProvider = CGDataProvider(data: data as CFData)!

        let cgImage:CGImage? = CGImage(width: width, height: height, bitsPerComponent: bitsPerComponent, bitsPerPixel: bitsPerPixel, bytesPerRow: width * 4, space: rgbColorSpace, bitmapInfo: bitmapInfo, provider: providerRef, decode: nil, shouldInterpolate: false, intent: .defaultIntent)
        
        guard let cgImage2 = cgImage else {
            assertionFailure()
            return nil;
        }
        return UIImage(cgImage: cgImage2)
    }
}


extension ViewController {
    private func navigateToPoint(x px:Int, y py:Int)
    {
        let x = (px - 16)/32;
        let y = (py - 58)/24;

        guard x>=0 && x<19 && y>=0 && y<13 else {
            return;
        }
        
        navigateToBlock(x:x, y:y)
    }
    
    private func navigateClear() {
        map = Array(repeating: Array(repeating:.none, count:19), count:13)
    }
    
    private func navigateToBlock(x bx:Int, y by:Int) {
        guard let pacPos = cdman.pacPos() else {
            cdman.press(.enter)
            return
        }
        
        map = Array(repeating: Array(repeating:.none, count:19), count:13)
        map[by][bx] = .stop
        
        
        for _ in 1...30 {
            let old = map

            for (y, row) in old.enumerated() {
                for (x, b) in row.enumerated() {
                    if b == .none {
                        continue
                    }
                    
                    let pos = CdmanPos(x: x, y: y)
                    let graph = cdman.pacGraph(at: pos)
                    
                    if graph.contains(.up), map[y-1][x] == .none {
                        map[y-1][x] = .down
                    }
                    if graph.contains(.down), map[y+1][x] == .none {
                        map[y+1][x] = .up
                    }
                    if graph.contains(.left), map[y][x-1] == .none {
                        map[y][x-1] = .right
                    }
                    if graph.contains(.right), map[y][x+1] == .none {
                        map[y][x+1] = .left
                    }
                }
            }
            if map[pacPos.y][pacPos.x] != .none {
                break
            }
        }
    }
    private func navigate() {
        guard let pacPos = cdman.pacPos(),
              map.count > 0
        else {
            return
        }
        
        if pacPos.x != lastPos.x || pacPos.y != lastPos.y {
            map[lastPos.y][lastPos.x] = .none
            lastPos = pacPos
        }
        
        let go = map[pacPos.y][pacPos.x]
        guard go != .none else {
            return
        }
        
        switch (go) {
        case .up:
            cdman.pacGo(.up)
        case .down:
            cdman.pacGo(.down)
        case .left:
            cdman.pacGo(.left)
        case .right:
            cdman.pacGo(.right)
        default:
            break
        }
    }
}
