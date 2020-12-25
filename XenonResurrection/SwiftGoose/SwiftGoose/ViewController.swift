//
//  ViewController.swift
//  SwiftGoose
//
//  Created by Gabriel Valky on 12/25/20.
//

import UIKit

class ViewController: UIViewController {
    var timer: Timer? = nil
    let goose = GooseWrapper()
    let image = UIImageView()
    
    override var shouldAutorotate: Bool {
        return true
    }
    
    override var prefersHomeIndicatorAutoHidden: Bool {
        return true
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.timer = Timer.scheduledTimer(timeInterval: 0.03, target: self, selector: #selector(handleTimer), userInfo: nil, repeats: true)
        
        image.translatesAutoresizingMaskIntoConstraints = false
        self.view.addSubview(image);
        
        NSLayoutConstraint.activate([
            image.leadingAnchor.constraint(equalTo: self.view.leadingAnchor),
            image.trailingAnchor.constraint(equalTo: self.view.trailingAnchor),
            image.topAnchor.constraint(equalTo: self.view.topAnchor),
            image.bottomAnchor.constraint(equalTo: self.view.bottomAnchor),
        ])

        let value = UIInterfaceOrientation.landscapeLeft.rawValue
        UIDevice.current.setValue(value, forKey: "orientation")
    }

    @objc func handleTimer(_ timer: Timer) {
        print("Timer ticking!")        
        goose.run()
        image.image = imageFromARGB32Bitmap( data:goose.getImageData(), width:320, height:200)
    }

    func imageFromARGB32Bitmap(data: Data, width: size_t, height: size_t) -> UIImage? {
        let bitsPerComponent: size_t = 8
        let bitsPerPixel: size_t = 24
        let rgbColorSpace = CGColorSpaceCreateDeviceRGB()
        let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.none.rawValue)
            .union(.byteOrder32Little)
        
        let providerRef:CGDataProvider = CGDataProvider(data: data as CFData)!

        let cgImage:CGImage? = CGImage(width: width, height: height, bitsPerComponent: bitsPerComponent, bitsPerPixel: bitsPerPixel, bytesPerRow: width * 3, space: rgbColorSpace, bitmapInfo: bitmapInfo, provider: providerRef, decode: nil, shouldInterpolate: true, intent: .defaultIntent)
        
        guard let cgImage2 = cgImage else {
            assertionFailure()
            return nil;
        }
        return UIImage(cgImage: cgImage2)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        let touch = event?.allTouches?.first
        let touchPoint = touch?.location(in: self.image)
        let rx = touchPoint!.x / self.image.frame.width
        let px = Int32(rx*320)
        goose.setPosition(px)
    }
}

